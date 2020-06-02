cmake_minimum_required(VERSION 3.15)
project(SeamCarving)
find_package (Threads)
set(CMAKE_CXX_STANDARD 17)

add_library(SeamCarvingLib create_energy_matric.cpp make_energy_cell.cpp process_deletions.cpp process_energy_matrix.cpp SeamCarving.cpp SeamCarving.h Test.cpp)

add_executable(SeamTest TestSeamCarving.cpp)

target_link_libraries(SeamTest SeamCarvingLib)