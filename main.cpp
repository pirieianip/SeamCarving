#include <iostream>
#include <future>
#include "Helpers/File.h"
#include "Helpers/StringManip.h"
#include "SeamCarvingLib/SeamCarving.h"
#include "Helpers/TranslateNintey.h"
#include "Helpers/create_adjacency_vector.h"

/**
 * main
 * Description: This is the main program described in the README.txt
 * @param size
 * @param arg
 * @return
 */
int main(int size, char** arg) {
    if(size == 4) {
        int verticalSeams, horizontalSeams, columns, rows, unneeded;
        std::string temp;
        auto fileAsync = std::async(getFile, arg[1]);
        {
            auto verticalAsync = std::async(getNum, arg[2]);
            auto horizontalAsync = std::async(getNum, arg[3]);

            verticalSeams = verticalAsync.get();
            horizontalSeams = horizontalAsync.get();
        }
            std::stringstream buffer(fileAsync.get());
            std::getline(buffer, temp);
            std::getline(buffer, temp);

            buffer >> columns >> rows >> unneeded;
            if(verticalSeams < columns && horizontalSeams < rows) {

            auto adjacency_vector = create_adjacency_vector(columns, rows, buffer);

            for (int i = 0; i < verticalSeams; ++i) {
                SeamCarvingLib::SeamCarving(columns - i, rows, adjacency_vector);
            }

            adjacency_vector = rotateNinety(columns - verticalSeams, rows, adjacency_vector);

            for (int i = 0; i < horizontalSeams; ++i) {
                SeamCarvingLib::SeamCarving(rows - i, columns - verticalSeams, adjacency_vector);
            }

            adjacency_vector = rotateNinetyR(rows - horizontalSeams, columns - verticalSeams, adjacency_vector);

            outputFile(arg[1], columns - verticalSeams, rows - horizontalSeams, adjacency_vector);
        } else
            std::cout << "File has less lines then seams wanted to carve\n";
    }
    else{
        std::cout << "Invalid number of Arguements.\n"
                  << "Valid Arguement is \"SeamCarving filename columns_carved rows_carved\"\n\n";
    }
    return 0;
}
