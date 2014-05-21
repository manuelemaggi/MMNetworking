//
//  MMURLConnection.h
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

#ifndef __MMURLpp__MMURLConnection__
#define __MMURLpp__MMURLConnection__

#include <iostream>
#include <pthread.h>
#include <curl/curl.h>
#include "MMURLRequest.h"
#include "MMURLDataBuffer.h"
#include "MMURLResponse.h"
#include "MMURLConnectionDelegate.h"

class MMURLConnection {

protected:
    
    static CURLcode _curlGlobalInitCode;
    static CURLcode CurlGlobalInit();
    
    MMURLRequest _request;
    pthread_t _tid;
    CURL *_curl;
    MMURLDataBuffer *_headerBuffer;
    MMURLDataBuffer *_bodyBuffer;
    MMURLResponse _response;
    MMURLConnectionDelegate *_delegate;

    void SetRequest(const MMURLRequest& request);
    void* Perform();
    static void* PerformHelper(void *context) { return ((MMURLConnection *)context)->Perform(); };
    
    static size_t HandleResponse(void *ptr, size_t size, size_t nmemb, void *context);
    static size_t HandleBody(void *ptr, size_t size, size_t nmemb, void *context);
    
    void test(MMURLResponse& response);
    
public:
    
    // Create connection
    
    MMURLConnection(const MMURLRequest& request);
    virtual ~MMURLConnection();
    
    MMURLRequest Request() { return _request; };
    
    void SetDelegate(MMURLConnectionDelegate *delegate) { _delegate = delegate; };
    
    // Manage connection
    
    void Start();
    void Cancel();
};

void testFp(MMURLResponse& response);

#endif /* defined(__MMURLpp__MMURLConnection__) */
