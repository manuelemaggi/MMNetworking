//
//  MMURLRequest.h
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

#ifndef __MMURLpp__MMURLRequest__
#define __MMURLpp__MMURLRequest__

#include <iostream>
#include "MMURL.h"
#include "MMURLTypes.h"

class MMURLRequest {
    
protected:
    
    MMURL _URL;
    MMURL_TimeInterval_t _timeout;
    std::string _method;
    
public:
    
    // Constants
    static const std::string METHOD_GET;
    static const std::string METHOD_POST;
    static const std::string METHOD_PUT;
    static const std::string METHOD_DELETETE;
    
    // Creating Requests

    MMURLRequest() { MMURLRequest(""); };
    MMURLRequest(const MMURL& URL);
    
    //  Request Properties
    
    MMURL URL();
    
    void setTimeOutInterval(MMURL_TimeInterval_t timeout) { _timeout = timeout; };
    MMURL_TimeInterval_t TimeOutInterval () { return _timeout; };
    
    // HTTP Request Properties
    
    void SetMethod(std::string method) { _method = method; };
    std::string Method () { return _method; };
    
    ~MMURLRequest();
};

#endif /* defined(__MMURLpp__MMURLRequest__) */
