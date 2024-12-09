# Copyright (c) Microsoft Corporation.
# Licensed under the MIT License.

cmake_minimum_required(VERSION 3.16)

project(msquic_platform_external)

find_package(msquic CONFIG REQUIRED)

message(STATUS "CMAKE_INSTALL_PREFIX: ${CMAKE_INSTALL_PREFIX}")

include(FetchContent)
FetchContent_Declare(
    googletest
    SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/../../../../submodules/googletest
)
FetchContent_MakeAvailable(googletest)

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
target_link_libraries(msquicplatformtest PRIVATE gtest msquic::msquic msquic::msquic_platform ws2_32 ntdll ncrypt crypt32 iphlpapi)
get_target_property(defs_inc msquic::inc COMPILE_DEFINITIONS)
message(STATUS "defs_inc: ${defs_inc}")

# message(STATUS "CMAKE_C_FLAGS: " ${CMAKE_C_FLAGS})
# message(STATUS "CMAKE_CXX_FLAGS: " ${CMAKE_CXX_FLAGS})
# message(STATUS "CFLAGS: " ${CFLAGS})
# message(STATUS "CXXFLAGS: " ${CMAKE_C_FLAGS})

remove_definitions(QUIC_EVENTS_STDOUT)
target_compile_definitions(msquicplatformtest PRIVATE QUIC_EVENTS_STUB _DISABLE_STRING_ANNOTATION)
get_target_property(defs_after msquicplatformtest COMPILE_DEFINITIONS)
message(STATUS "defs_after: ${defs_after}")
