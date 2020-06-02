//
// Created by ian on 4/28/20.
//

#ifndef SEAMCARVING_TRANSLATENINTEY_H
#define SEAMCARVING_TRANSLATENINTEY_H

#include <vector>

/***
 * rotateNinety
 * Description: rotates adjacency list 90 degrees
 * @param columns
 * @param rows
 * @param buffer
 * @return rotated adjacency list
 * Location of Function: TranslateNintey.cpp
 */
std::vector<std::vector<unsigned short>> rotateNinety(const int columns, const int rows, const std::vector<std::vector<unsigned short>>& buffer);

/***
 * rotateNinetyR
 * Description: Rotates adjacency list 90 degress ccw
 * @param columns
 * @param rows
 * @param buffer
 * @return
 * Location of Function: TranslateNinteyR.cpp
 */
std::vector<std::vector<unsigned short>> rotateNinetyR(const int columns, const int rows, const std::vector<std::vector<unsigned short>>& buffer);


#endif //SEAMCARVING_TRANSLATENINTEY_H
