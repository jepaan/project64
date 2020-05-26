cmake_minimum_required(VERSION 3.1.0)

project(Project64)

SET(CMAKE_CXX_FLAGS_DEBUG "-g -O0")
SET(CMAKE_C_FLAGS_DEBUG "-g -O0")


add_subdirectory(Source)

# add the executable
#add_executable(Tutorial tutorial.cxx)
