//
// Created by ian on 4/27/20.
//

#ifndef SEAMCARVING_FILE_H
#define SEAMCARVING_FILE_H

#include <string>
#include <vector>
/***
 * getFile
 * Description: Takes file name and returns file contents.
 * @param filename
 * @return contents of file
 * Location of function: getFile.cpp
 */
std::string getFile(const std::string& filename);

/***
 * outputFile
 * Description: Outputs in P2 pgm format.
 * @param filename
 * @param column
 * @param row
 * @param adj_vec
 * Location of function: outputFile.cpp
 */
void outputFile(const std::string& filename, int column, int row, const std::vector<std::vector<unsigned short>>& adj_vec);

#endif //SEAMCARVING_FILE_H
