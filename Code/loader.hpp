#ifndef LOADER_HPP
#define LOADER_HPP
#include <string>
class loader{
private:   
    std::string file;
public:
    loader(std::string file);
    std::string load();
};

#endif