//
//  main.cpp
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

#include <iostream>
#include <unistd.h>
#include "MMcURLConnection.h"

int main(int argc, const char * argv[])
{
    MMcURL url = MMcURL("http://curl.haxx.se/");
    MMcURLRequest request = MMcURLRequest(url);
    request.setHTTPMethod(MMcURL_HTTPMethod_GET);
    MMcURLConnection connection = MMcURLConnection(request);
    connection.Start();
    
    sleep(5);
    
    return 0;
}

