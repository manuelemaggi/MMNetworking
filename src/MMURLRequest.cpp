//
//  MMURLRequest.cpp
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

#include "MMURLRequest.h"

const std::string MMURLRequest::METHOD_GET      = "GET";
const std::string MMURLRequest::METHOD_POST     = "POST";
const std::string MMURLRequest::METHOD_PUT      = "PUT";
const std::string MMURLRequest::METHOD_DELETETE = "DELETE";

static const MMURL_TimeInterval_t kDefaultTimeOut = 30.0;

MMURLRequest::MMURLRequest(const MMURL& URL) {
    
    _URL = URL;
    _timeout = kDefaultTimeOut;
}

MMURLRequest::~MMURLRequest() {
    
}

MMURL MMURLRequest::URL() {
    
    return _URL;
}
