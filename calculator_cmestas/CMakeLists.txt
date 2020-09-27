cmake_minimum_required(VERSION 3.5)

project(calculator_cmestas LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB files "*.h" "*.cpp")

add_executable(calculator_cmestas ${files} main.cpp)
