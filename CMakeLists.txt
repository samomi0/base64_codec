cmake_minimum_required(VERSION 3.5)

project(Base64Codec)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(OUTPUT_LIB_NAME base64)

option(BUILD_TEST "BUILD_TEST" on)

include_directories(${CMAKE_SOURCE_DIR}/include)

add_subdirectory(${CMAKE_SOURCE_DIR}/src)

add_subdirectory(${CMAKE_SOURCE_DIR}/example)

if(BUILD_TEST)
  message(STATUS "Enable BUILD_TEST=on")
  
  find_package(GTest REQUIRED)
  add_subdirectory(${CMAKE_SOURCE_DIR}/test)
endif(BUILD_TEST)

