cmake_minimum_required(VERSION 3.11)
set(PROJECT_NAME Algorithms)
project(${PROJECT_NAME})

include_directories(${CMAKE_SOURCE_DIR}/DataStructures ${CMAKE_SOURCE_DIR}/Algorithms)
link_directories(${CMAKE_BINARY_DIR}/lib)

aux_source_directory(. DIR_SRC)
add_library(${PROJECT_NAME} SHARED ${DIR_SRC})
target_link_libraries(${PROJECT_NAME} ${CMAKE_DL_LIBS} DataStructures)
