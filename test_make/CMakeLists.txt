cmake_minimum_required(VERSION 3.5.1)

set(CMAKE_CXX_STANDARD 17)

project(hello_cmake)

add_executable(hellooo main.cpp src/hello.cpp src/random.cpp)
