cmake_minimum_required(VERSION 3.0.0)
project(lab VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 17)

include(CTest)
enable_testing()

add_executable(lab main.cpp flowerbed.h flowerbed.cpp functions.h functions.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

cmake_minimum_required(VERSION 3.12) # version can be different

project(tests) #name of your project
add_subdirectory(googletest) # add googletest subdirectory
include_directories(googletest/include) # this is so we can #include <gtest/gtest.h>
add_executable(googletest tests.cpp flowerbed.h flowerbed.cpp functions.h functions.cpp) # add this executable
target_link_libraries(googletest PRIVATE gtest) # link google test to this executable