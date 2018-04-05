cmake_minimum_required(VERSION 3.7)
project(intro-a-la-computacion)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES "TP1/main.cpp" "TP1/función 2.cpp")
add_executable(TP1 ${SOURCE_FILES})
