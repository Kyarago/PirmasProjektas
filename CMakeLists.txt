cmake_minimum_required(VERSION 3.17)
project(ND1_Su_Vektoriais)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(ND1_Su_Vektoriais
        Lbib.h
        Lfun.cpp
        Mbib.h
        Mfun.cpp
        "ND1 Su Vektoriais.cpp")
