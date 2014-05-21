//
//  MMURLData.h
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

#ifndef __MMURLpp__MMURLData__
#define __MMURLpp__MMURLData__

#include <iostream>

class MMURLData {
    
protected:
    
    void *_data;
    size_t _lenght;
    
public:
    
    MMURLData ();
    MMURLData (void *data, size_t lenght);
    virtual ~MMURLData ();
    
    void* Data();
    size_t Lenght();
};

#endif /* defined(__MMURLpp__MMURLData__) */
