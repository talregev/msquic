# Copyright (c) Microsoft Corporation.
# Licensed under the MIT License.

set(SOURCES
    PerfClient.cpp
    PerfServer.cpp
    SecNetPerfMain.cpp
    Tcp.cpp
)

add_library(perflib STATIC ${SOURCES})

set_property(TARGET perflib PROPERTY FOLDER "${QUIC_FOLDER_PREFIX}perf")

target_link_libraries(perflib PUBLIC)

target_link_libraries(perflib PRIVATE inc warnings)

target_include_directories(perflib PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}>
    $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>)

if(MSVC)
    target_compile_options(perflib PUBLIC /wd4459)
endif()
