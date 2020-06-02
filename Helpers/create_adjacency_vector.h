//
// Created by ian on 4/28/20.
//

#ifndef SEAMCARVING_CREATE_ADJACENCY_VECTOR_H
#define SEAMCARVING_CREATE_ADJACENCY_VECTOR_H

#include <vector>
#include <sstream>

/***
 * create_adjacency_vector
 * Description: Creates a adjacency list from a given stringstream.
 * @param columns
 * @param rows
 * @param buffer
 * @return
 * Location of Function: create_adjacency_vector.cpp
 */
std::vector<std::vector<unsigned short>> create_adjacency_vector(int columns, int rows, std::stringstream& buffer);

#endif //SEAMCARVING_CREATE_ADJACENCY_VECTOR_H
