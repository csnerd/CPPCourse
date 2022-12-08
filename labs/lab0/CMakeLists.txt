cmake_minimum_required(VERSION 3.9)
project(lab0 CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

set (SOURCES 
      main.cpp
      accumulator.cpp
    )


add_executable(lab0 ${SOURCES})
target_include_directories(lab0 PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

# compile test
add_executable(accumulator_test accumulator_test.cpp accumulator.cpp)
target_include_directories(accumulator_test PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(accumulator_test ${CONAN_LIBS})