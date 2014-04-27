//
//  MMcURLRequest.cpp
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

#include "MMcURLRequest.h"

static const MMcURL_TimeInterval_t kDefaultTimeOut = 30.0;

MMcURLRequest::MMcURLRequest(const MMcURL& URL) {
    
    _URL = URL;
    _timeout = kDefaultTimeOut;
}

MMcURLRequest::~MMcURLRequest() {
    
}

MMcURL MMcURLRequest::URL() {
    
    return _URL;
}
