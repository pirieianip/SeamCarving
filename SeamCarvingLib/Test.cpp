//
// Created by ian on 4/30/20.
//
#include <iostream>
#include "SeamCarving.h"

void SeamCarvingLib::test() {
    int tests = 0, passed = 0;
    {
        std::vector<std::vector<unsigned short>> adj_test = {{30, 120, 196}, {215, 198, 180}, {45, 4, 172}, {5, 250, 252}, {190, 192, 53}, {35, 123, 124}, {5, 100, 132}, {110, 114, 203}};
        std::vector<std::vector<int>> verify_energy = {{275,244,92},{372,307,42},{251,649,256},{470,551,281},{342,268,409},{273,181,80},{230,164,111},{109,107,160}};
        std::vector<std::vector<int>> test_init_processed = {{275,244,92},{-1,-1,-1},{-1,-1,-1},{-1,-1,-1},{-1,-1,-1},{-1,-1,-1},{-1,-1,-1},{-1,-1,-1}};
        std::vector<std::vector<int>> test_processed = {{275,244,92},{616,399,134},{650,783,390},{1120,941,671},{1283,939,1080},{1212,1120,1019},{1350,1183,1130},{1292,1237,1290}};
        std::vector<std::vector<int>> final_test = {{30,120},{215,198},{135,4},{210,252},{192,53},{123,124},{5,132},{46,203}};

        auto energy_test = create_energy_matrix(adj_test, 3, 8);

        for(int r = 0; r < verify_energy.size(); ++r){
            for(int c = 0; c < verify_energy[0].size(); ++c){
                if(verify_energy[r][c] == energy_test[r][c]){
                    ++passed;
                } else
                    std::cout << "Location fail: (" << r << "," << c << "): " << energy_test[r][c] << " != " << verify_energy[r][c] << "\n";
                ++tests;
            }
        }

        auto processed_test = initialize_processed_matrix(3,8,verify_energy);
        for(int r = 0; r < verify_energy.size(); ++r){
            for(int c = 0; c < verify_energy[0].size(); ++c){
                if(processed_test[r][c] == test_init_processed[r][c]){
                    ++passed;
                } else
                    std::cout << "Location fail: (" << r << "," << c << "): " << energy_test[r][c] << " != " << verify_energy[r][c] << "\n";
                ++tests;
            }
        }

        process_energy_matrix(3,energy_test,processed_test);
        for(int r = 0; r < verify_energy.size(); ++r){
            for(int c = 0; c < verify_energy[0].size(); ++c){
                if(processed_test[r][c] == test_processed[r][c]){
                    ++passed;
                } else
                    std::cout << "Location fail: (" << r << "," << c << "): " << energy_test[r][c] << " != " << verify_energy[r][c] << "\n";
                ++tests;
            }
        }
        process_deletions(8, 3, processed_test, adj_test);
        for(auto r: adj_test){
            for(auto c: r)
                std::cout << c << " ";
            std::cout << "\n";
        }
    }
    std::cout << "Tests: " << tests << "\nPassed: " << passed << "\n\n";
}
