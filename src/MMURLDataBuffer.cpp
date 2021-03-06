//
//  MMURLDataBuffer.cpp
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

#include "MMURLDataBuffer.h"

MMURLDataBuffer::MMURLDataBuffer () {

    _lenght = 0;
    _data = NULL;
}

void MMURLDataBuffer::AppendData(void *data, size_t lenght) {
    
    if (lenght <= 0) {
        return;
    }
    
    if (_data == NULL) {
        _data = malloc(lenght);
    }
    else {
        _data = realloc(_data, (_lenght + lenght));
    }
    
    char *tempPtr = static_cast<char*>(_data);
    
    memcpy(tempPtr+_lenght, data, lenght);
    _lenght += lenght;
}

