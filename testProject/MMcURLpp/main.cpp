//
//  main.cpp
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

#include <iostream>
#include <unistd.h>
#include "MMURLConnection.h"

void responseHandler(MMURLResponse& response, void* conext);

int main(int argc, const char * argv[])
{
    MMURLConnectionDelegate delegate = MMURLConnectionDelegate(&responseHandler, NULL);

    MMURL url = MMURL("http://curl.haxx.se/");
    MMURLRequest request = MMURLRequest(url);
    MMURLConnection connection = MMURLConnection(request);
    connection.SetDelegate(&delegate);
    
    connection.Start();
    sleep(5);
    
    return 0;
}

void responseHandler(MMURLResponse& response, void* conext) {

    std::cout << "Response code : " << response.ResponseCode() << std::endl;
}
