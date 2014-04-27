//
//  MMcURLRequest.h
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

#ifndef __MMcURLpp__MMcURLRequest__
#define __MMcURLpp__MMcURLRequest__

#include <iostream>
#include "MMcURL.h"
#include "MMcURLTypes.h"

class MMcURLRequest {
    
protected:
    MMcURL _URL;
    MMcURL_TimeInterval_t _timeout;
    MMcURL_HTTPMethod_t _httpMethod;
    
public:
    
    //  Creating Requests

    MMcURLRequest() { MMcURLRequest(""); };
    MMcURLRequest(const MMcURL& URL);
    
    //  Request Properties
    
    MMcURL URL();
    
    void setTimeOutInterval(MMcURL_TimeInterval_t timeout) { _timeout = timeout; };
    MMcURL_TimeInterval_t TimeOutInterval () { return _timeout; };
    
    // HTTP Request Properties
    
    void setHTTPMethod(MMcURL_HTTPMethod_t httpMethod) { _httpMethod = httpMethod; };
    MMcURL_HTTPMethod_t HTTPMethod () { return _httpMethod; };
    
    ~MMcURLRequest();
};

#endif /* defined(__MMcURLpp__MMcURLRequest__) */
