cmake_minimum_required(VERSION 3.11)
set(PROJECT_NAME DataStructuresTesting)
project(${PROJECT_NAME})

aux_source_directory(. DIR_SRC)
add_executable(${PROJECT_NAME} ${DIR_SRC})

set(DsLib ${CMAKE_BINARY_DIR}/lib/libDataStructures.so)
include_directories(${CMAKE_SOURCE_DIR}/DataStructures )

target_link_libraries(${PROJECT_NAME} ${CMAKE_DL_LIBS} ${DsLib})
