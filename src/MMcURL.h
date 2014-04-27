//
//  MMcURL.h
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

#ifndef __MMcURLpp__MMcURL__
#define __MMcURLpp__MMcURL__

#include <iostream>

class MMcURL : public std::string {
    
public:
    MMcURL(void) : std::string() {}
    MMcURL(const char* ch) : std::string(ch) {}
    MMcURL(const std::string& str) : std::string(str) {}
    MMcURL(const MMcURL& path) : std::string(path) {}
};

#endif /* defined(__MMcURLpp__MMcURL__) */
