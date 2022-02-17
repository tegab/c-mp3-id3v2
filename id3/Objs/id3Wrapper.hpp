//
//  id3Wrapper.hpp
//  id3
//
//  Created by OneOn on 2022-02-16.
//

#ifndef id3Wrapper_hpp
#define id3Wrapper_hpp
#include <map>
#include <stdio.h>
#include <string>

using namespace std;


map<string, string> GetId3Tag (string pathURL);
bool isValidFile(string filepath);


#endif /* id3Wrapper_hpp */
