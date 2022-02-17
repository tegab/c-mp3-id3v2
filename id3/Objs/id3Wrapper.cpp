//
//  id3Wrapper.cpp
//  id3
//  Note: Taglib collect and display information
//  Created by OneOn on 2022-02-16.
//

#include "id3Wrapper.hpp"
#include <map>
#include <string>
#include <stdio.h>
#import <Tag/tfilestream.h>
#import <Tag/fileref.h>
#import <Tag/tstring.h>
#import <Tag/mpegfile.h>
#import <Tag/tstringlist.h>
#import <Tag/tpropertymap.h>
#import <Tag/tfilestream.h>
#include <Tag/id3v2tag.h>
#include <Tag/id3v2frame.h>
#include <Tag/id3v2header.h>
#import <Tag/textidentificationframe.h>
using namespace std;


map<std::string, string> GetId3Tag(string pathURL){
    
    const char *file_path = pathURL.data();
    map<string, string> id3_map;
    

    if (isValidFile(pathURL)){  //Check if media is a valid mp3
        
        
        //File reference
        TagLib::FileRef file_ref(file_path);
        TagLib::MPEG::File *File = dynamic_cast<TagLib::MPEG::File *>(file_ref.file());
        TagLib::ID3v2::Tag *id3_tag = File->ID3v2Tag();
        
        
        //Loop through id3 tags
        for( TagLib::ID3v2::FrameList::ConstIterator it = id3_tag->frameList().begin();
            it != id3_tag->frameList().end(); ++it )
        {

            TagLib::String frame_Id = TagLib::String( (*it)->frameID() );
            string str_frameid = frame_Id.toCString(true);
            
            
            if (!str_frameid.compare("APIC") || !str_frameid.compare("GEOB") || !str_frameid.compare("COMM") || !str_frameid.compare("RVA2")){
                
                //Unsupported id3 tag information
                cout << frame_Id << ": "  << "Unsupported" <<   endl;
               
            } else {

                
                TagLib::ID3v2::TextIdentificationFrame *tag_centent = dynamic_cast< TagLib::ID3v2::TextIdentificationFrame * >( *it ); // cast id3 tag content
                
                
                //add content to map
                id3_map[str_frameid] = tag_centent->fieldList().toString().toCString(true);
                
                //Display id3 name and content
                cout << frame_Id << ": "  <<  tag_centent->fieldList().toString().toCString(true) <<   endl;
            }
        }

        return id3_map;
        
   
    } else {
        
        return id3_map;
        
    }

}


 bool isValidFile(string pathURL){
     
     const char *filepath = pathURL.data();
     
    TagLib::FileStream *stream = new TagLib::FileStream(filepath);
     
    if (!stream->isOpen()) {
        delete stream;
        cout << "Unable to open FileStream"  << endl;
        return false;
    }
    if (TagLib::MPEG::File::isSupported(stream)) {
        cout << "Valid media"  << endl;
        return true;
        
    } else {
        cout << "Not a valid media"  << endl;
        return false;
    }
    
}
