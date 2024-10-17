# Copyright (c) Microsoft Corporation.
# Licensed under the MIT License.

cmake_minimum_required(VERSION 3.16)

project(msquic_platform_external)

find_package(msquic REQUIRED)
find_library(MSPLATFORM_LIBRARIES
             NAMES msquic_platform)

message(STATUS "CMAKE_INSTALL_PREFIX: ${CMAKE_INSTALL_PREFIX}")
message(STATUS "MSPLATFORM_LIBRARIES: ${MSPLATFORM_LIBRARIES}")

include(FetchContent)

set(OTHER_TERGETS "")

if(QUIC_TLS STREQUAL "openssl" OR  QUIC_TLS STREQUAL "openssl3")
    # add_library(OpenSSL INTERFACE)
    string(TOLOWER ${CMAKE_SYSTEM_PROCESSOR} SYSTEM_PROCESSOR)
    FetchContent_Declare(
        OpenSSLQuic
        SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/../../../../submodules
        CMAKE_ARGS "-DQUIC_USE_SYSTEM_LIBCRYPTO=${QUIC_USE_SYSTEM_LIBCRYPTO}"
    )
    FetchContent_MakeAvailable(OpenSSLQuic)

    target_link_libraries(OpenSSL
        INTERFACE
        OpenSSLQuic::OpenSSLQuic
    )

    list(APPEND OTHER_TERGETS OpenSSL)
endif()



FetchContent_Declare(
    googletest
    SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/../../../../submodules/googletest
)
FetchContent_MakeAvailable(googletest)

set(SOURCES
    ../main.cpp
    # ../CryptTest.cpp
    # ../DataPathTest.cpp
    # ../PlatformTest.cpp
    # ../StorageTest.cpp
    ../TlsTest.cpp
)

add_executable(msquicplatformtest ${SOURCES})

target_include_directories(msquicplatformtest PRIVATE ${CMAKE_INSTALL_PREFIX}/include)
target_link_libraries(msquicplatformtest PRIVATE msquic ${MSPLATFORM_LIBRARIES} ${OTHER_TERGETS} gtest ws2_32 schannel ntdll bcrypt ncrypt crypt32 iphlpapi advapi32 secur32 userenv onecore winmm clang_rt.asan_dbg_dynamic-x86_64 clang_rt.asan_dynamic-x86_64)
target_compile_definitions(msquicplatformtest PRIVATE QUIC_EVENTS_STUB QUIC_LOGS_STUB _DISABLE_VECTOR_ANNOTATION _DISABLE_STRING_ANNOTATION)
