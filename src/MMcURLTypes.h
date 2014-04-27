//
//  MMcURLTypes.h
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

#ifndef MMcURLpp_MMcURLTypes_h
#define MMcURLpp_MMcURLTypes_h

typedef double MMcURL_TimeInterval_t;

typedef enum {
    
    MMcURL_HTTPMethod_GET = 0,
    MMcURL_HTTPMethod_POST,
    MMcURL_HTTPMethod_PUT,
    MMcURL_HTTPMethod_DELETE,
    
} MMcURL_HTTPMethod_t;

typedef enum {
    
    MMcURL_RESPONSE_CODE_OK = 200,
    
} MMcURL_RESPONSE_CODE_t;

#endif
