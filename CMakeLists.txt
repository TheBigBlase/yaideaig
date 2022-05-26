cmake_minimum_required(VERSION 3.10)

# set the project name
project(yaideaig)
set(CMAKE_CXX_STANDARD 20)

# add the executable
set(files
	src/attribut.cpp
	src/attribut.hpp
	src/classes.cpp
	src/classes.hpp
	src/example.cpp
	src/example.hpp
	src/readFile.cpp
	src/readFile.hpp
	src/trainingSet.cpp
	src/trainingSet.hpp
	)

set(CMAKE_CXX_FLAGS_DEBUG_INIT "-Wall")

add_executable(yaideaig 
	src/main.cpp
	${files})
