cmake_minimum_required(VERSION 3.30.0)

add_library(ClientNetwork STATIC)

target_sources(ClientNetwork PRIVATE Network.cpp)
target_include_directories(ClientNetwork PUBLIC .)
