//
//  MMURLConnectionDelegate.h
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

#ifndef __MMURLpp__MMURLConnectionDelegate__
#define __MMURLpp__MMURLConnectionDelegate__

#include <iostream>
#include "MMURLResponse.h"

class MMURLConnectionDelegate {
    
private:
    
    typedef void (*func_ptr_t)(MMURLResponse&, void*);
    void *_context;
    func_ptr_t _fp;
    
public:
    
    MMURLConnectionDelegate(func_ptr_t fp, void* context) {
        
        _fp = fp;
        _context = context;
    }
    
    void Invoke(MMURLResponse& param) {
        
        if (_fp != NULL) {
            (*_fp)(param, _context);
        }
    }
};

#endif /* defined(__MMURLpp__MMURLConnectionDelegate__) */
