# Copyright (c) 2020 ARM Limited. All rights reserved.
# SPDX-License-Identifier: Apache-2.0

add_library(ntp-client INTERFACE)

target_include_directories(ntp-client
    INTERFACE
        .
)

target_sources(ntp-client
    INTERFACE
        NTPClient.cpp
)

target_link_libraries(ntp-client
    INTERFACE
        mbed-netsocket
)
