# Copyright (c) Microsoft Corporation.
# Licensed under the MIT License.

find_package(msquic REQUIRED)
find_package(GTest REQUIRED)
FIND_LIBRARY(MSPLATFORM_LIBRARIES
             NAMES msquic_platform)

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

target_link_libraries(msquicplatformtest msquic ${MSPLATFORM_LIBRARIES} ncrypt crypt32 GTest::GTest)

# if (BUILD_SHARED_LIBS)
#     target_link_libraries(msquicplatformtest ${MSPLATFORM_LIBRARIES} ncrypt crypt32)
# endif()

# target_link_libraries(msquicplatformtest inc gtest warnings logging base_link)

# add_test(NAME msquicplatformtest
#          COMMAND msquicplatformtest
#          WORKING_DIRECTORY ${QUIC_OUTPUT_DIR})
