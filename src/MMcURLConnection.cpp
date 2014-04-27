//
//  MMcURLConnection.cpp
//  MMcURLpp
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

#include "MMcURLConnection.h"
#include "MMcURLHTTPUtilities.h"
#include <unistd.h>

typedef CURLcode MMcURLcode;
static const MMcURLcode MMcURLCodeInvalid = (CURLcode)(-1);

CURLcode MMcURLConnection::_curlGlobalInitCode = MMcURLCodeInvalid;
CURLcode MMcURLConnection::CurlGlobalInit () {
    
    if (CURLE_OK != _curlGlobalInitCode) {
        _curlGlobalInitCode = curl_global_init(CURL_GLOBAL_ALL);
    }
    
    return _curlGlobalInitCode;
}

MMcURLConnection::MMcURLConnection(const MMcURLRequest& request) {
    
    CurlGlobalInit();
    _curl = curl_easy_init();
    _headerBuffer = new MMcURLDataBuffer();
    _bodyBuffer = new MMcURLDataBuffer();
    
    SetRequest(request);
}

MMcURLConnection::~MMcURLConnection() {

    this->Cancel();
    delete _headerBuffer;
    delete _bodyBuffer;
}

void MMcURLConnection::Start() {
    
    int error;
    error = pthread_create(&_tid,
                           NULL, /* default attributes please */
                           MMcURLConnection::PerformHelper,
                           (void*)this);
}

void MMcURLConnection::Cancel() {
    
    if (_curl) {
        curl_easy_cleanup(_curl);
    }
    if (_tid) {
        pthread_cancel(_tid);
    }
}

#pragma mark - Private functions

void MMcURLConnection::SetRequest(const MMcURLRequest& request) {
    
    _request = request;
    
    curl_easy_setopt(_curl, CURLOPT_URL, _request.URL().c_str());
    curl_easy_setopt(_curl, CURLOPT_TIMEOUT, _request.TimeOutInterval());
    curl_easy_setopt(_curl, CURLOPT_CUSTOMREQUEST, RequestOptionWithHTTPMethod(_request.HTTPMethod()));
}

size_t MMcURLConnection::HandleResponse(void *ptr, size_t size, size_t nmemb, void *context) {

    MMcURLConnection *connection = static_cast<MMcURLConnection*>(context);
    connection->_headerBuffer->AppendData(ptr, nmemb);
    
    // End of Headers stream
    if (nmemb == 2) {
        long code;
        curl_easy_getinfo(connection->_curl, CURLINFO_RESPONSE_CODE, &code);
        std::cout << code << std::endl;
    }

    return size*nmemb;
}

size_t MMcURLConnection::HandleBody(void *ptr, size_t size, size_t nmemb, void *context) {
    
    MMcURLConnection *connection = static_cast<MMcURLConnection*>(context);
    connection->_bodyBuffer->AppendData(ptr, nmemb);
    
    return size*nmemb;
}

void* MMcURLConnection::Perform() {

    curl_easy_setopt(_curl, CURLOPT_HEADERDATA, this);
    curl_easy_setopt(_curl, CURLOPT_HEADERFUNCTION, MMcURLConnection::HandleResponse);
    
    curl_easy_setopt(_curl, CURLOPT_WRITEDATA, this);
    curl_easy_setopt(_curl, CURLOPT_WRITEFUNCTION, MMcURLConnection::HandleBody);
    
    curl_easy_perform(_curl); /* ignores error */
    
    return NULL;
}

