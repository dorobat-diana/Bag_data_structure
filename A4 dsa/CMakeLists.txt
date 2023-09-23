cmake_minimum_required(VERSION 3.24)
project(A4_dsa)

set(CMAKE_CXX_STANDARD 14)

include_directories("Bag (1)")

add_executable(A4_dsa
        "Bag (1)/App.cpp"
        "Bag (1)/Bag.cpp"
        "Bag (1)/Bag.h"
        "Bag (1)/BagIterator.cpp"
        "Bag (1)/BagIterator.h"
        "Bag (1)/ExtendedTest.cpp"
        "Bag (1)/ExtendedTest.h"
        "Bag (1)/ShortTest.cpp"
        "Bag (1)/ShortTest.h")
