# Copyright (c) Microsoft Corporation.
# Licensed under the MIT License.

find_package(msquic REQUIRED)
FIND_LIBRARY(MSPLATFORM_LIBRARIES
             NAMES msquic_platform)
# FIND_LIBRARY(GTEST_LIBRARIES names gtest)
message(STATUS "MSPLATFORM_LIBRARIES: ${MSPLATFORM_LIBRARIES}")
message(STATUS "CMAKE_CURRENT_SOURCE_DIR: ${CMAKE_CURRENT_SOURCE_DIR}")

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

# target_include_directories(msquicplatformtest PRIVATE ${PROJECT_SOURCE_DIR}/src/core)

# set_property(TARGET msquicplatformtest PROPERTY FOLDER "${QUIC_FOLDER_PREFIX}tests")
# set_property(TARGET msquicplatformtest APPEND PROPERTY BUILD_RPATH "$ORIGIN")

target_link_libraries(msquicplatformtest msquic ${MSPLATFORM_LIBRARIES} ncrypt crypt32 gtest)

# if (BUILD_SHARED_LIBS)
#     target_link_libraries(msquicplatformtest ${MSPLATFORM_LIBRARIES} ncrypt crypt32)
# endif()

# target_link_libraries(msquicplatformtest inc gtest warnings logging base_link)

# add_test(NAME msquicplatformtest
#          COMMAND msquicplatformtest
#          WORKING_DIRECTORY ${QUIC_OUTPUT_DIR})
