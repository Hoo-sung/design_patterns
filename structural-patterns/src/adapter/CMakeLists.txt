cmake_minimum_required(VERSION 3.10)

project(AdapterPatternExample VERSION 1.0)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(AdapterPatternExample main.cpp)

install(TARGETS AdapterPatternExample DESTINATION ${CMAKE_SOURCE_DIR}/bin)
