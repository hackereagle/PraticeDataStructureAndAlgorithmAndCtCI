cmake_minimum_required(VERSION 3.11)
set(PROJECT_NAME CrackingTheCodingInterviewExercises)
project(${PROJECT_NAME})

aux_source_directory(. DIR_SRC)
add_executable(${PROJECT_NAME} ${DIR_SRC})

set(AlgmLib ${CMAKE_BINARY_DIR}/lib/libAlgorithms.so)
set(DsLib ${CMAKE_BINARY_DIR}/lib/libDataStructures.so)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../DataStructures ${CMAKE_CURRENT_SOURCE_DIR}/../Algorithms ${CMAKE_CURRENT_SOURCE_DIR}/../Common)

target_link_libraries(${PROJECT_NAME} ${CMAKE_DL_LIBS} ${DsLib} ${AlgmLib})
