//
// Created by ian on 4/28/20.
//

#include "SeamCarving.h"

void SeamCarvingLib::process_deletions(int Rows, int Columns,
                                       const std::vector<std::vector<int>>& processed_matrix,
                                       std::vector<std::vector<unsigned short>>& adjacency_vector) {
    std::vector<int> positions;
    int least = 2147483647, position = 0;


    for(int i = 0; i < Columns; ++i){
        if(processed_matrix[Rows - 1][i] < least) {
            least = processed_matrix[Rows - 1][i];
            position = i;
        }
    }
    positions.emplace_back(position);
    for(int r = Rows - 2; r > -1; --r){
        least = 2147483647;
        /// check left
        if(positions.back() > 0 && processed_matrix[r][positions.back()-1] < least) {
            least = processed_matrix[r][positions.back() - 1];
            position = positions.back() - 1;
        }
        /// check center
        if(processed_matrix[r][positions.back()] < least){
            least = processed_matrix[r][positions.back()];
            position = positions.back();
        }
        /// check right
        if(positions.back() < Columns - 1 && processed_matrix[r][positions.back()+1] < least){
            least = processed_matrix[r][positions.back()+1];
            position = positions.back() + 1;
        }
        positions.emplace_back(position);
    }

    for(int r = 0; r < Rows; ++r){
        adjacency_vector[r].erase(adjacency_vector[r].begin() + positions.back());
        positions.pop_back();
    }
}