cmake_minimum_required(VERSION 4.2)
project(LMS)

set(CMAKE_CXX_STANDARD 14)

add_executable(LMS
        src/main.cpp
        src/signup.cpp
        src/signup.h
        src/login.cpp
        src/login.h
        src/add.cpp
        src/add.h
        src/list.h
        src/list.cpp
        src/main.h)
