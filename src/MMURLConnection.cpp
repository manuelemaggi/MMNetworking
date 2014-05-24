//
//  MMURLConnection.cpp
//  MMURLpp
//
//  Created by Manuele Maggi on 27/04/14.
//  email: manuele.maggi@gmail.com
//  Copyright (c) 2014 Manuele Maggi. All rights reserved.
//
//  Licensed under the Apache License, Version 2.0 (the "License");
//  you may not use this file except in compliance with the License.
//  You may obtain a copy of the License at
//
//  http://www.apache.org/licenses/LICENSE-2.0
//
//  Unless required by applicable law or agreed to in writing, software
//  distributed under the License is distributed on an "AS IS" BASIS,
//  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
//  See the License for the specific language governing permissions and
//  limitations under the License.
//

#include "MMURLConnection.h"
#include <unistd.h>

typedef CURLcode MMURLcode;
static const MMURLcode MMURLCodeInvalid = (CURLcode)(-1);

CURLcode MMURLConnection::_curlGlobalInitCode = MMURLCodeInvalid;
CURLcode MMURLConnection::CurlGlobalInit () {
    
    if (CURLE_OK != _curlGlobalInitCode) {
        _curlGlobalInitCode = curl_global_init(CURL_GLOBAL_ALL);
    }
    
    return _curlGlobalInitCode;
}

MMURLConnection::MMURLConnection(const MMURLRequest& request) {
    
    CurlGlobalInit();
    _curl = curl_easy_init();
    _headerBuffer = new MMURLDataBuffer();
    _bodyBuffer = new MMURLDataBuffer();
    _response = MMURLResponse();
    _delegate = NULL;
    
    SetRequest(request);
}

MMURLConnection::~MMURLConnection() {

    this->Cancel();
    delete _headerBuffer;
    delete _bodyBuffer;
}

void MMURLConnection::Start() {
    
    int error;
    error = pthread_create(&_tid,
                           NULL, /* default attributes please */
                           MMURLConnection::PerformHelper,
                           (void*)this);
}

void MMURLConnection::Cancel() {
    
    if (_curl) {
        curl_easy_cleanup(_curl);
        _curl = NULL;
    }
    if (_tid) {
        pthread_cancel(_tid);
    }
}

#pragma mark - Private functions

void MMURLConnection::SetRequest(const MMURLRequest& request) {
    
    _request = request;
    
    curl_easy_setopt(_curl, CURLOPT_URL, _request.URL().c_str());
    curl_easy_setopt(_curl, CURLOPT_TIMEOUT, _request.TimeOutInterval());
    curl_easy_setopt(_curl, CURLOPT_CUSTOMREQUEST,
                     (_request.Method().length() > 0 ? _request.Method().c_str() : MMURLRequest::METHOD_GET.c_str()));
}

size_t MMURLConnection::HandleResponse(void *ptr, size_t size, size_t nmemb, void *context) {

    MMURLConnection *connection = static_cast<MMURLConnection*>(context);
    connection->_headerBuffer->AppendData(ptr, nmemb);

    // End of Headers stream
    if (nmemb == 2) {
        long code;
        curl_easy_getinfo(connection->_curl, CURLINFO_RESPONSE_CODE, &code);

        connection->_response.SetResponseCode(MMURL_RESPONSE_CODE_t(code));
    }

    return size*nmemb;
}

size_t MMURLConnection::HandleBody(void *ptr, size_t size, size_t nmemb, void *context) {
    
    MMURLConnection *connection = static_cast<MMURLConnection*>(context);
    connection->_bodyBuffer->AppendData(ptr, nmemb);
    
    return size*nmemb;
}

void* MMURLConnection::Perform() {

    curl_easy_setopt(_curl, CURLOPT_HEADERDATA, this);
    curl_easy_setopt(_curl, CURLOPT_HEADERFUNCTION, MMURLConnection::HandleResponse);
    
    curl_easy_setopt(_curl, CURLOPT_WRITEDATA, this);
    curl_easy_setopt(_curl, CURLOPT_WRITEFUNCTION, MMURLConnection::HandleBody);
    
    curl_easy_perform(_curl);
    _curl = NULL;

    _response.SetData(*_bodyBuffer);
    _response.SetHeadersData(*_headerBuffer);

    if (_delegate != NULL) {
        _delegate->Invoke(_response);
    }
    
    return NULL;
}

