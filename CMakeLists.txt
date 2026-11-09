cmake_minimum_required(VERSION 3.20)

project(AlgorithmsAndStructures)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Main src/main.cpp src/array.h src/hashmap.h)

# Google Test
include(FetchContent)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(
    Tests
    src/array.ut.cxx
    src/hashmap.ut.cxx
)

target_link_libraries(
    Tests
    GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(Tests)