cmake_minimum_required(VERSION 3.20)

project(local_tools)

add_executable(
    local_tools

    ./lib/*.c
    ./lib/*.h
    ./lib/*.cc
    ./lib/*.hh
)
