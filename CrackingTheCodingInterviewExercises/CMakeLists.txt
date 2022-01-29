cmake_minimum_required(VERSION 3.11)
set(${PROJECT_NAME} CrackingTheCodingInterviewExercises)
project(${PROJECT_NAME})

aux_source_directory(. DIR_SRC)
add_executable(${PROJECT_NAME} ${DIR_SRC})

include_directories(${CMAKE_SOURCE_DIR}/DataStructures ${CMAKE_SOURCE_DIR}/Algorithms)
link_directories(${CMAKE_BINARY_DIR}/lib)

target_link_libraries(${PROJECT_NAME} ${CMAKE_DL_LIBS} DataStructures Algorithms)
