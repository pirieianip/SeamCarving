//
// Created by ian on 4/27/20.
//

#ifndef SEAMCARVING_SEAMCARVING_H
#define SEAMCARVING_SEAMCARVING_H


#include <vector>


/**
 * C Style Lib
 */
class SeamCarvingLib {

    /***
     * create_energy_matrix
     * Description: Returns the energy matrix of a Given adjacency List
     * @param adjacency_vector
     * @param column
     * @param row
     * @return the energy Matrix of an adjacency list
     * Location of Function: create_energy_matrix.cpp
     */
    static std::vector<std::vector<int>> create_energy_matrix(
                                        const std::vector<std::vector<unsigned short>>& adjacency_vector,
                                        int column, int row);

    /***
     * make_energy_cell
     * Description: Takes indexes of a given adjacency list and finds the energy, returning that value.
     * @param adjacency_vector
     * @param column
     * @param row
     * @param columnIndex
     * @param rowIndex
     * @return returns the value of a single cell of given indexes
     * Location of Function: make_energy_cell.cpp
     */
    static int make_energy_cell(const std::vector<std::vector<unsigned short>>& adjacency_vector,
                                        int column, int row,
                                        int columnIndex, int rowIndex);

    /***
     * initialize_processed_matrix
     * Description: Creates the outline of a processed energy adjacency list.
     * @param column
     * @param row
     * @param energy_matrix
     * @return An outline of a processed energy adjacency list
     * Location of Function: process_energy_matrix.cpp
     */
    static std::vector<std::vector<int>> initialize_processed_matrix(int column, int row,
                                        std::vector<std::vector<int>> energy_matrix);

    /***
     * process_energy_matrix
     * Description: Fills out the processed energy adjacency list in its entirety.
     * @param column
     * @param energy_matrix
     * @param processed_matrix
     * Location of Function: process_energy_matrix.cpp
     */
    static void process_energy_matrix(int column,
                                        const std::vector<std::vector<int>>& energy_matrix,
                                        std::vector<std::vector<int>>& processed_matrix);

    /**
     * process_energy_cell
     * Description: Processed a single cell of an energy adjacency list.
     * @param column
     * @param rowIndex
     * @param columnIndex
     * @param energy_matrix
     * @param processed_matrix
     * @return the value of energy for a single cell of the energy adjacency list.
     */
    static int process_energy_cell(int column,
                                        int rowIndex,
                                        int columnIndex,
                                        const std::vector<std::vector<int>>& energy_matrix,
                                        const std::vector<std::vector<int>>& processed_matrix);

    /***
     * process_deletions
     * Description: Searches through the last row of the processed energy adjacency list and notes position
     * continues from left, right or center of last point noting each lowest processed cell. Once noting all
     * of the lowest values, deletes those cells
     * @param Rows
     * @param Columns
     * @param processed_matrix
     * @param adjacency_vector
     * Location of Function: process_deletion.cpp
     */
    static void process_deletions(int Rows, int Columns,
                                        const std::vector<std::vector<int>>& processed_matrix,
                                        std::vector<std::vector<unsigned short>>& adjacency_vector);

public:
    /***
     * SeamCarving
     * Description: This is the driver for the reason of the private functions, it create the energy adjacency list,
     * processed adjacency list and then calls the deletion function.
     * @param columns
     * @param rows
     * @param adjacency_vector
     * Location of Function: SeamCarving.cpp
     */
    static void SeamCarving(int columns, int rows, std::vector<std::vector<unsigned short>>& adjacency_vector);

    /***
     * test
     * Description: This is a bit of test driven programming to ensure some reasonable correctness through the program.
     * Loction of Function: Test.cpp
     */
    static void test();
};




#endif //SEAMCARVING_SEAMCARVING_H
