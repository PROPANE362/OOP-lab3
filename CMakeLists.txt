cmake_minimum_required(VERSION 3.14)
project(Figures CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.tar.gz
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

include_directories(${PROJECT_SOURCE_DIR}/include)

add_library(figures_lib STATIC
    src/Square.cpp
    src/Rectangle.cpp
    src/Trapezoid.cpp
    src/Array.cpp
)
target_include_directories(figures_lib PUBLIC ${PROJECT_SOURCE_DIR}/include)

add_executable(main src/main.cpp)
target_link_libraries(main figures_lib)

enable_testing()

add_executable(tests tests/test_figures.cpp)
target_link_libraries(tests figures_lib GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(tests)
