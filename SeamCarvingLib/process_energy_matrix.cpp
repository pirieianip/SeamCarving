//
// Created by ian on 4/28/20.
//

#include "SeamCarving.h"

void SeamCarvingLib::process_energy_matrix(int column,
                                           const std::vector<std::vector<int>>& energy_matrix,
                                           std::vector<std::vector<int>>& processed_matrix) {
    for(int r = 1; r < energy_matrix.size(); ++r) {
        for (int c = 0; c < column; ++c) {
            processed_matrix[r][c] = process_energy_cell(column, r, c, energy_matrix, processed_matrix);
        }
    }
}

int SeamCarvingLib::process_energy_cell(int column,
                                        int rowIndex,
                                        int columnIndex,
                                        const std::vector<std::vector<int>>& energy_matrix,
                                        const std::vector<std::vector<int>>& processed_matrix){
    int least = processed_matrix[rowIndex][columnIndex];

    /// check left
    if((columnIndex > 0) &&
            (processed_matrix[rowIndex - 1][columnIndex - 1] + energy_matrix[rowIndex][columnIndex] < least ||
            least == -1))
        least = processed_matrix[rowIndex - 1][columnIndex - 1] + energy_matrix[rowIndex][columnIndex];

    /// check center
    if(processed_matrix[rowIndex - 1][columnIndex] + energy_matrix[rowIndex][columnIndex] < least || least == -1)
        least = processed_matrix[rowIndex - 1][columnIndex] + energy_matrix[rowIndex][columnIndex];

    /// check right
    if((columnIndex < column - 1) &&
            (processed_matrix[rowIndex-1][columnIndex + 1] + energy_matrix[rowIndex][columnIndex] < least ||
            least == -1))
        least = processed_matrix[rowIndex-1][columnIndex + 1] + energy_matrix[rowIndex][columnIndex];

    return least;
}

std::vector<std::vector<int>>
SeamCarvingLib::initialize_processed_matrix(int column, int row, std::vector<std::vector<int>> energy_matrix) {
    std::vector<std::vector<int>> ret;
    std::vector<int> initializer(column, -1);
    ret.reserve(row);
    ret.emplace_back(energy_matrix[0]);
    for(int i = 1; i < row; ++i)
        ret.push_back(initializer);

    return ret;
}



