cmake_minimum_required(VERSION 3.20)
project(office-reader VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(pptx)

include(CMakePackageConfigHelpers)

export(TARGETS 
    pptx
    FILE ${CMAKE_CURRENT_BINARY_DIR}/office-readerTargets.cmake
    NAMESPACE office-reader::
)