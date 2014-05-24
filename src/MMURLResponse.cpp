//
//  MMURLResponse.cpp
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

#include "MMURLResponse.h"

MMURLResponse::MMURLResponse() {
    
    _data = NULL;
    SetResponseCode(0);
}

MMURLResponse::MMURLResponse(MMURL_RESPONSE_CODE_t responseCode, MMURLData &data) {
    
    SetData(data);
    SetResponseCode(responseCode);
}

MMURLResponse::~MMURLResponse() {
    
    if (_data != NULL) {
        delete _data;
    }
}

MMURL_RESPONSE_CODE_t MMURLResponse::ResponseCode() {
    
    return _responseCode;
}

void MMURLResponse::SetResponseCode(MMURL_RESPONSE_CODE_t code) {
    
    _responseCode = code;
}

void MMURLResponse::SetData(MMURLData& data) {
    
    _data = new MMURLData(data);
}

void MMURLResponse::SetHeadersData(MMURLData& data) {
    
    _headers = std::string(static_cast<char*>(data.Data()), data.Lenght());    
}

std::string MMURLResponse::Headers() {
    
    return _headers;
}

MMURLData MMURLResponse::Data() {
    
    return *_data;
}
