cmake_minimum_required(VERSION 3.15)
project(SeamCarving)
find_package (Threads)
set(CMAKE_CXX_STANDARD 17)

add_library(Helpers create_adjacency_vector.cpp create_adjacency_vector.h File.h getFile.cpp getNum.cpp StringManip.h TranslateNintey.cpp TranslateNintey.h translateNinteyR.cpp outputFile.cpp)

add_executable(Test_Helpers Test.cpp)
target_link_libraries(Test_Helpers Helpers)