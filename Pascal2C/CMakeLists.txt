cmake_minimum_required(VERSION 3.10)
project(Pascal2C VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find required packages
find_package(FLEX REQUIRED)
find_package(BISON REQUIRED)

# Include directories
include_directories(
    ${CMAKE_CURRENT_BINARY_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/include
    ${CMAKE_CURRENT_SOURCE_DIR}/src
)

# Add source directory
add_subdirectory(src)

# Google Test setup
option(BUILD_TESTS "Build tests" ON)
if(BUILD_TESTS)
    # Find the system-installed GoogleTest package
    find_package(GTest REQUIRED)
    
    # Enable testing
    enable_testing()
    
    # Add tests directory
    add_subdirectory(tests)
endif() 