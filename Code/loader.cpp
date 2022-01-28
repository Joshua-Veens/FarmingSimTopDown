#include "loader.hpp"
#include "base64.hpp"
#include <fstream>
#include <sstream>
#include <iostream>
loader::loader(std::string file): file(file){}

std::string loader::load(){
    std::ifstream rFile(file);
    std::ostringstream buffer;
    char ch;
    while(rFile.get(ch)){
        buffer << ch;
    }
    std::string to_decode = buffer.str();
    return base64_decode(to_decode);
}