//
// Created by ian on 4/29/20.
//
#include <sstream>
#include <iostream>
#include "File.h"
#include "StringManip.h"
#include "TranslateNintey.h"
#include "create_adjacency_vector.h"

/***
 * This is a main Driver program to test the various different functions of the Helper section.
 * @return
 */
int main(){

    int tests = 0;
    int testCount = 0;

    {
        std::string testString = "1 2 3 4 5 6 7 8 9";
        std::stringstream testStream(testString);

        auto testAdjVec = create_adjacency_vector(3,3,testStream);
        int count = 1;
        for (int r = 0; r < testAdjVec.size(); ++r) {
            for (int c = 0; c < testAdjVec[r].size(); ++c) {
                if (testAdjVec[r][c] == count){
                    ++tests;
                }
                else
                    std::cout << "Fail: Location: (" << r << "," << c << "): was: " << testAdjVec[r][c] << " Suppsed to be: " << count << "\n";
                ++testCount;
                ++count;
            }
        }
        testAdjVec = rotateNinety(3, 3, testAdjVec);
        count = 1;
        for(int c = 0; c < testAdjVec[0].size();++c){
            for(int r = 0; r < testAdjVec.size();++r){
                if (testAdjVec[r][c] == count){
                    ++tests;
                }
                else
                    std::cout << "Fail: Location: (" << r << "," << c << "): was: " << testAdjVec[r][c] << " Suppsed to be: " << count << "\n";
                ++testCount;
                ++count;            }
        }
        testAdjVec = rotateNinetyR(3, 3, testAdjVec);
        count = 1;
        for (int r = 0; r < testAdjVec.size(); ++r) {
            for (int c = 0; c < testAdjVec[r].size(); ++c) {
                if (testAdjVec[r][c] == count){
                    ++tests;
                }
                else
                    std::cout << "Fail: Location: (" << r << "," << c << "): was: " << testAdjVec[r][c] << " Suppsed to be: " << count << "\n";
                ++testCount;
                ++count;
            }
        }

    }
    {
        int columns, rows, unneeded;
        std::string temp = getFile("test.txt"), tmp;
        std::stringstream buffer(temp);

        std::getline(buffer,tmp);
        std::getline(buffer,tmp);
        buffer >> columns >> rows >> unneeded;

        if(columns == 3)
            ++tests;
        else
            std::cout << "Columns incorrectly read: " << columns << "\n";
        ++testCount;

        if(rows == 3)
            ++tests;
        else
            std::cout << "Rows incorrectly read: " << rows << "\n";
        ++testCount;

        auto testAdjVec = create_adjacency_vector(columns,rows,buffer);
        int count = 1;
        for (int r = 0; r < testAdjVec.size(); ++r) {
            for (int c = 0; c < testAdjVec[r].size(); ++c) {
                if (testAdjVec[r][c] == count){
                    ++tests;
                }
                else
                    std::cout << "Fail: Location: (" << r << "," << c << "): was: " << testAdjVec[r][c] << " Suppsed to be: " << count << "\n";
                ++testCount;
                ++count;
            }
        }
        testAdjVec = rotateNinety(3, 3, testAdjVec);
        count = 1;
        for(int c = 0; c < testAdjVec[0].size();++c){
            for(int r = 0; r < testAdjVec.size();++r){
                if (testAdjVec[r][c] == count){
                    ++tests;
                }
                else
                    std::cout << "Fail: Location: (" << r << "," << c << "): was: " << testAdjVec[r][c] << " Suppsed to be: " << count << "\n";
                ++testCount;
                ++count;            }
        }
        testAdjVec = rotateNinetyR(3, 3, testAdjVec);
        count = 1;
        for (int r = 0; r < testAdjVec.size(); ++r) {
            for (int c = 0; c < testAdjVec[r].size(); ++c) {
                if (testAdjVec[r][c] == count){
                    ++tests;
                }
                else
                    std::cout << "Fail: Location: (" << r << "," << c << "): was: " << testAdjVec[r][c] << " Suppsed to be: " << count << "\n";
                ++testCount;
                ++count;
            }
        }
        outputFile("test.txt",testAdjVec.size(),testAdjVec[0].size(),testAdjVec);
    }
    {
        std::vector<std::vector<unsigned short>> test = {{1,2},{3,4},{5,6}};
        auto testflip = rotateNinety(2, 3, test);
        for(auto r: testflip){
            for(auto c: r)
                std::cout << c << " ";
            std::cout << "\n";
        }
        auto testrflip = rotateNinetyR(3, 2, testflip);
        for(auto r: testrflip){
            for(auto c: r)
                std::cout << c << " ";
            std::cout << "\n";
        }
    }
    std::cout << "Tests: " << testCount << "\nFail: " << tests - testCount << "\n";
}