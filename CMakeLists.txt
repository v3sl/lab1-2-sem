cmake_minimum_required(VERSION 3.0.0)
project(lab VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 17)

include(CTest)
enable_testing()

add_executable(lab main.cpp functions.h functions.cpp class4.h class4.h class11.h)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)