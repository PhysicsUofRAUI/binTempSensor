cmake_minimum_required(VERSION 3.0)

project(custom_libraries)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

include_directories(bin_sensor_library)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "-g -O0 -Wall -Wextra -pedantic-errors")

# Test runner
add_library(test_runner STATIC
        test_runner.cpp)
        
        


add_executable(DHT_U
        DHT_U.cpp)
target_link_libraries(DHT_U test_runner)

add_executable(bin_sensor
        bin_sensor.cpp)
target_link_libraries(bin_sensor test_runner)
