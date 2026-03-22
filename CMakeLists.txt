# 1. Set the minimum CMake version
cmake_minimum_required(VERSION 3.10)

# 2. Name your project
project(HashMap_Implementation)

# 3. Specify the C++ standard (matches your intellisense JSON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 4. Create the executable using your .cpp file
add_executable(HashMap_Implementation hashMap.cpp)