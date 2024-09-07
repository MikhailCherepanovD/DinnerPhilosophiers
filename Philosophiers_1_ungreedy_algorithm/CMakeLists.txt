cmake_minimum_required(VERSION 3.27)
project(0709PhilosophiesMyImpementation)

set(CMAKE_CXX_STANDARD 17)

add_executable(0709PhilosophiesMyImpementation main.cpp
        Philosopher.cpp
        Philosopher.h
        Fork.cpp
        Fork.h
        libs.h)
