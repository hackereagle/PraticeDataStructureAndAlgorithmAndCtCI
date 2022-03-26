cmake_minimum_required(VERSION 3.11)
set(PROJECT_NAME PraticeDataStructureAndAlgorithmAndCtCI)
project(${PROJECT_NAME})

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# compile option
set(CMAKE_CXX_STANDAED 17)
set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_VERBOSE_MAKEFILE ON)

add_subdirectory(src/logResp)
add_subdirectory(src/DataStructures)
add_subdirectory(src/DataStructures.Testing)
add_subdirectory(src/Algorithms)
add_subdirectory(src/Algorithms.Testing)
add_subdirectory(src/CrackingTheCodingInterviewExercises)
