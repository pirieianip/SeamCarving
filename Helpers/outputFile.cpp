//
// Created by ian on 4/30/20.
//
#include <fstream>
#include <vector>
#include "File.h"

void outputFile(const std::string& filename, int column, int row, const std::vector<std::vector<unsigned short>>& adj_vec){
    std::string new_file_name = filename.substr(0, filename.rfind('.')) + "_processed.pgm";

    std::ofstream ofs(new_file_name);
    ofs << "P2\n#Carved by icp3 - SeamCarving Project\n" << column << " " << row << "\n255\n";
    for(const auto& r: adj_vec){
        for(const auto& c: r){
            ofs << c << " ";
        }
        ofs << "\n";
    }
    ofs.close();
}
