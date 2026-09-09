cmake_minimum_required(VERSION 3.16)
project(cpp_algorithms_and_data_structures LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_library(algorithms src/algorithms.cpp)
target_include_directories(algorithms PUBLIC include)

target_compile_options(algorithms PRIVATE -Wall -Wextra -Wpedantic)

add_executable(algorithms_demo examples/main.cpp)
target_link_libraries(algorithms_demo PRIVATE algorithms)

aadd_executable(algorithms_tests tests/test_algorithms.cpp)
target_link_libraries(algorithms_tests PRIVATE algorithms)

enable_testing()
add_test(NAME algorithms_tests COMMAND algorithms_tests)
