#include <iostream>
#include <fstream>
#include "IO.hpp"
using namespace std;

IO::IO(const string &file_path){

    // open a connection to the file 
    file_stream.open(file_path, ios::in | ios::out | ios::binary);

    // if file is not able to be opened, then print a message
    if(!file_stream.is_open()){
        cout << "Unable to open the file: " << file_path << endl;
    }
}


std::fstream& IO::getFileStream(){
    return file_stream;
}
// if file is open then close it!
IO::~IO(){
    if(file_stream.is_open()){
        file_stream.close();
    }
}