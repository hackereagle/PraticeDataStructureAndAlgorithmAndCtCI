cmake_minimum_required(VERSION 3.10.0)
set(PROJECT_NAME Logger)
aux_source_directory(. DIR_SRC)

set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)

if(MSVC)
	#add_library(${PROJECT_NAME} STATIC ${DIR_SRC})
	add_library(${PROJECT_NAME} SHARED ${DIR_SRC})
	target_link_libraries(${PROJECT_NAME} ${CMAKE_DL_LIBS} Threads::Threads)
else()
	add_library(${PROJECT_NAME} SHARED ${DIR_SRC})
	target_link_libraries(${PROJECT_NAME} ${CMAKE_DL_LIBS} stdc++fs Threads::Threads)
endif(MSVC)

