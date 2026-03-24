cmake_minimum_required(VERSION 3.10)

# Name of your project
project(HashMap_Implementation)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Create the executable from main.cpp and hashMap.cpp
add_executable(HashMap_Implementation main.cpp hashMap.cpp)