//
//  main.mm
//  id3
//  Note: Paste url of any any mp3,
//  it will return the media id3
//  tag information using Taglib
//  Created by OneOn on 2022-02-16.
//
#import <Foundation/Foundation.h>
#include "id3Wrapper.hpp"
#include <map>
#include <string>
#include <iostream>
#include <stdio.h>

using namespace std;

int main(int argc, const char * argv[]) {
    @autoreleasepool {
        
        string mp3_url;
        cout << "Enter Mp3 URL:" << endl;
        cin >> mp3_url;
        auto _ = GetId3Tag(mp3_url); //return id3 tags as map<string, string>
        
        
        
    }
    return 0;
}
