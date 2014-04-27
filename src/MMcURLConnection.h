//
//  MMcURLConnection.h
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

#ifndef __MMcURLpp__MMcURLConnection__
#define __MMcURLpp__MMcURLConnection__

#include <iostream>
#include <pthread.h>
#include <curl/curl.h>
#include "MMcURLRequest.h"
#include "MMcURLDataBuffer.h"
#include "MMcURLResponse.h"

class MMcURLConnection {

protected:
    static CURLcode _curlGlobalInitCode;
    static CURLcode CurlGlobalInit();
    
    MMcURLRequest _request;
    pthread_t _tid;
    CURL *_curl;
    MMcURLDataBuffer *_headerBuffer;
    MMcURLDataBuffer *_bodyBuffer;

    void SetRequest(const MMcURLRequest& request);
    void* Perform();
    static void* PerformHelper(void *context) { return ((MMcURLConnection *)context)->Perform(); };
    
    static size_t HandleResponse(void *ptr, size_t size, size_t nmemb, void *context);
    static size_t HandleBody(void *ptr, size_t size, size_t nmemb, void *context);
    
public:
    
    // Create connection
    
    MMcURLConnection(const MMcURLRequest& request);
    virtual ~MMcURLConnection();
    
    MMcURLRequest Request() { return _request; };
    
    // Manage connection
    
    void Start();
    void Cancel();
};

#endif /* defined(__MMcURLpp__MMcURLConnection__) */
