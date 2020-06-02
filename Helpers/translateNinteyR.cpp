//
// Created by ian on 4/28/20.
//
#include "TranslateNintey.h"

std::vector<std::vector<unsigned short>> rotateNinetyR(const int columns, const int rows, const std::vector<std::vector<unsigned short>>& buffer){
    std::vector<std::vector<unsigned short>> ret;

    for(int c = 0; c < columns; ++c){
        std::vector<unsigned short> row_to_column;
        for(int r = 0; r < rows; ++r){
            row_to_column.push_back(buffer[r][c]);
        }
        ret.emplace_back(row_to_column);
    }

    return ret;
}
