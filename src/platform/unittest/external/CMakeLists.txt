# Copyright (c) Microsoft Corporation.
# Licensed under the MIT License.

if ("${CMAKE_HOST_SYSTEM_NAME}" STREQUAL "Windows")
    cmake_minimum_required(VERSION 3.20)
else()
    cmake_minimum_required(VERSION 3.16)
endif()

project(msquic_platform_external)

find_package(msquic REQUIRED)
find_library(MSPLATFORM_LIBRARIES
             NAMES msquic_platform)
find_library(GTEST_LIBRARIES names gtest)
message(STATUS "CMAKE_INSTALL_PREFIX: ${CMAKE_INSTALL_PREFIX}")
message(STATUS "MSPLATFORM_LIBRARIES: ${MSPLATFORM_LIBRARIES}")
message(STATUS "GTEST_LIBRARIES: ${GTEST_LIBRARIES}")

set(SOURCES
    ../main.cpp
    ../CryptTest.cpp
    ../DataPathTest.cpp
    ../PlatformTest.cpp
    # ../StorageTest.cpp
    ../TlsTest.cpp
)

add_executable(msquicplatformtest ${SOURCES})

target_include_directories(msquicplatformtest PRIVATE ${CMAKE_INSTALL_PREFIX}/include)
target_link_libraries(msquicplatformtest msquic ${MSPLATFORM_LIBRARIES} ncrypt crypt32 ${GTEST_LIBRARIES})

