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

# get_property(importTargets DIRECTORY "${CMAKE_SOURCE_DIR}" PROPERTY IMPORTED_TARGETS)
# message(STATUS "importTargets: ${importTargets}")

# get_target_property(defs msquic::inc INTERFACE_COMPILE_DEFINITIONS)
# message(STATUS "defs: ${defs}")
# list(FILTER defs EXCLUDE REGEX [[^QUIC_EVENTS_MANIFEST_ETW$]])
# set_property(TARGET msquic::inc PROPERTY INTERFACE_COMPILE_DEFINITIONS ${defs})

# get_target_property(defs msquic::msquic_platform INTERFACE_COMPILE_DEFINITIONS)
# message(STATUS "defs: ${defs}")

add_executable(msquicplatformtest ${SOURCES})
target_include_directories(msquicplatformtest PRIVATE ${CMAKE_INSTALL_PREFIX}/include)
target_link_libraries(msquicplatformtest PRIVATE gtest msquic::msquic msquic::msquic_platform ws2_32 ntdll ncrypt crypt32 iphlpapi)
target_compile_definitions(msquicplatformtest PRIVATE QUIC_EVENTS_STUB _DISABLE_STRING_ANNOTATION)

# get_target_property(defs msquic::inc INTERFACE_COMPILE_DEFINITIONS)
# message(STATUS "defs: ${defs}")
# get_target_property(defs msquicplatformtest INTERFACE_COMPILE_DEFINITIONS)
# message(STATUS "defs: ${defs}")

remove_definitions(-DQUIC_EVENTS_MANIFEST_ETW)
