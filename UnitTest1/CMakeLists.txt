cmake_minimum_required (VERSION 3.8)

project(tests)
find_package(GTest REQUIRED)

set(CMAKE_CXX_STANDARD 17)

include_directories(
    ../include
    ${GTEST_INCLUDE_DIRS}
)

include_directories(foo)

add_executable(main test.cpp)

enable_testing()
add_test(main "./Test")

target_link_libraries(main lib)