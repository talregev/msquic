# Copyright (c) Microsoft Corporation.
# Licensed under the MIT License.

set(SOURCES
    pcp.cpp
)

add_quic_tool(quicpcp ${SOURCES})

target_include_directories(quicpcp PRIVATE ${PROJECT_SOURCE_DIR}/src/core)
target_link_libraries(quicpcp core)
