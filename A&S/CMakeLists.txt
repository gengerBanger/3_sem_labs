cmake_minimum_required(VERSION 3.25)
project(timsort)

set(CMAKE_CXX_STANDARD 17)

add_executable(timsort main.cpp DynamicArr.h ConApp.cpp ConApp.h TimSort.cpp TimSort.h DynamicArr.cpp stack.cpp stack.h)
