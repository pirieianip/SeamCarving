//
// Created by ian on 4/28/20.
//

#include "SeamCarving.h"
#include <stdlib.h>

int
SeamCarvingLib::make_energy_cell(const std::vector<std::vector<unsigned short>> &adjacency_vector, int column, int row, int columnIndex, int rowIndex) {
    int ret = 0;
    /// add Left
    if(columnIndex > 0)
        ret += std::abs(adjacency_vector[rowIndex][columnIndex - 1] - adjacency_vector[rowIndex][columnIndex]);
    if(columnIndex < column - 1)
        ret += std::abs(adjacency_vector[rowIndex][columnIndex + 1] - adjacency_vector[rowIndex][columnIndex]);
    if(rowIndex > 0)
        ret += std::abs(adjacency_vector[rowIndex - 1][columnIndex] - adjacency_vector[rowIndex][columnIndex]);
    if(rowIndex < row - 1)
        ret += std::abs(adjacency_vector[rowIndex + 1][columnIndex] - adjacency_vector[rowIndex][columnIndex]);

    return ret;
}