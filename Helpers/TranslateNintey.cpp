//
// Created by ian on 4/28/20.
//

#include "TranslateNintey.h"

std::vector<std::vector<unsigned short>> rotateNinety(const int columns, const int rows, const std::vector<std::vector<unsigned short>>& buffer){
    std::vector<std::vector<unsigned short>> ret;
    ret.reserve(columns);

    for(int c = 0; c < columns; ++c){
        std::vector<unsigned short> temp;
        temp.reserve(rows);
        for(int r = 0; r < rows; ++r){
            temp.emplace_back(buffer[r][c]);
        }
        ret.emplace_back(temp);
    }
    return ret;
}