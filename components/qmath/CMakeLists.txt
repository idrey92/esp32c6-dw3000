#
# SPDX-FileCopyrightText: Copyright (c) 2024 Qorvo US, Inc.
# SPDX-License-Identifier: LicenseRef-QORVO-2
#
cmake_minimum_required(VERSION 3.13)

idf_component_register(
    SRCS "src/qmath.c"
    INCLUDE_DIRS "include"
)

