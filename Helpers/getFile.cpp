//
// Created by ian on 4/27/20.
//

#include <fstream>
#include "File.h"

std::string getFile(const std::string& filename){
    std::ifstream ifs(filename);
    std::string ret;

    ifs.seekg(0, std::ios::end);
    ret.reserve(ifs.tellg());
    ifs.seekg(0, std::ios::beg);

    ret.assign(std::istreambuf_iterator<char>(ifs),
            std::istreambuf_iterator<char>());

    return ret;
}
