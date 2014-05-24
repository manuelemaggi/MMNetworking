//
//  MMURLData.cpp
//  MMURLpp
//
//  Created by Manuele Maggi on 07/05/14.
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

#include "MMURLData.h"

MMURLData::MMURLData () {
    
    _lenght = 0;
    _data = NULL;
}

MMURLData::MMURLData (void *data, size_t lenght) {
    
    _lenght = 0;
    _data = NULL;

    if (lenght > 0) {
        
        _data = malloc(lenght);
        _data = memcpy(_data, data, lenght);
        _lenght = lenght;
    }
}

MMURLData::~MMURLData () {
    
    if (_data != NULL) {
        free(_data);
        _data = NULL;
        _lenght = 0;
    }
}

void* MMURLData::Data() {
    
    return _data;
}

size_t MMURLData::Lenght() {
    
    return _lenght;
}
