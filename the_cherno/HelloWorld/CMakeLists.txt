cmake_minimum_required(VERSION 3.10)
project(HelloWorld)

set(CMAKE_CXX_STANDARD 17)

file (GLOB SOURCES "src/*.cpp")

add_executable(helloworld ${SOURCES})

target_include_directories(helloworld PUBLIC include)