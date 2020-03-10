cmake_minimum_required (VERSION 3.8)

project ("CMakeProject1")

include_directories(lib)
add_subdirectory(lib)

include_directories(UnitTest1)
add_subdirectory(UnitTest1)