//
// Created by ian on 4/28/20.
//

#include "create_adjacency_vector.h"

std::vector<std::vector<unsigned short>> create_adjacency_vector(int columns, int rows, std::stringstream& buffer){
    std::vector<std::vector<unsigned short>> ret;
    unsigned short input = 0;

    ret.reserve(rows);
    for(int r = 0; r < rows; ++r ){
        std::vector<unsigned short> temp;
        temp.reserve(columns);
        for(int c = 0; c < columns; ++c){
            buffer >> input;
            temp.emplace_back(input);
        }
        ret.emplace_back(temp);
    }
    return ret;
}
