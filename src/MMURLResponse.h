//
//  MMURLResponse.h
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

#ifndef __MMURLpp__MMURLResponse__
#define __MMURLpp__MMURLResponse__

#include <iostream>
#include "MMURLTypes.h"
#include "MMURLData.h"

class MMURLResponse {
    
    friend class MMURLConnection;
    
protected:
    
    MMURL_RESPONSE_CODE_t _responseCode;
    MMURLData *_data;
    
    void SetResponseCode(MMURL_RESPONSE_CODE_t code);
    void SetData(MMURLData& data);
    
public:
    
    MMURLResponse();
    ~MMURLResponse();
    MMURLResponse(MMURL_RESPONSE_CODE_t responseCode, MMURLData &data);
    MMURL_RESPONSE_CODE_t ResponseCode();
};

#endif /* defined(__MMURLpp__MMURLResponse__) */
