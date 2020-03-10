cmake_minimum_required (VERSION 3.8)

project ("lib")

set(SOURCE_LIB list.cpp tree.cpp words.cpp)
set (CMAKE_CXX_STANDARD 17)

add_library(lib STATIC ${SOURCE_LIB})
