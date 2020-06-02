//
// Created by ian on 4/28/20.
//

#include "SeamCarving.h"

std::vector<std::vector<int>>
SeamCarvingLib::create_energy_matrix(const std::vector<std::vector<unsigned short>>& adjacency_vector, int column, int row) {
    std::vector<int> initializer(column, -1);
    std::vector<std::vector<int>> ret;
    ret.reserve(row);
    for(int i = 0; i < row; ++i)
        ret.push_back(initializer);

    for(int r = 0; r < row; ++r)
        for(int c = 0; c < column; ++c)
            ret[r][c] = make_energy_cell(adjacency_vector, column, row, c, r);

    return ret;
}





