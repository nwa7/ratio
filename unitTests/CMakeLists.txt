cmake_minimum_required(VERSION 3.13)

project(myUnitTests)

enable_testing()

find_package(GTest REQUIRED)
include(GoogleTest)

add_executable(unitTests src/sample_test.cpp)
target_link_libraries(unitTests PUBLIC ratio GTest::GTest GTest::Main)

target_compile_features(unitTests PRIVATE cxx_std_17) 
if (MSVC)
    #target_compile_options(myUnitTests PRIVATE /W3)
else()
    #target_compile_options(myUnitTests PRIVATE -Wall -Wextra -Wpedantic -pedantic-errors)
endif()


add_executable(speedTests src/speed_precision_test.cpp)
target_link_libraries(speedTests PRIVATE ratio)

target_compile_features(speedTests PRIVATE cxx_std_17) 
if (MSVC)
    #target_compile_options(myUnitTests PRIVATE /W3)
else()
    #target_compile_options(myUnitTests PRIVATE -Wall -Wextra -Wpedantic -pedantic-errors)
endif()


gtest_discover_tests(unitTests)