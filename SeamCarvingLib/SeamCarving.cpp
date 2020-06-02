//
// Created by ian on 4/27/20.
//

#include "SeamCarving.h"

void SeamCarvingLib::SeamCarving(int columns,
        int rows,
        std::vector<std::vector<unsigned short>>& adjacency_vector)
{
    auto energy_matrix = create_energy_matrix(adjacency_vector,columns,rows);
    auto process_matrix = initialize_processed_matrix(columns,rows,energy_matrix);
    process_energy_matrix(columns, energy_matrix, process_matrix);
    process_deletions(rows, columns, process_matrix, adjacency_vector);
}




