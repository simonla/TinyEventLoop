cmake_minimum_required(VERSION 3.10)
project(EventLoopDemo)

set(CMAKE_CXX_STANDARD 14)

add_executable(EventLoopDemo main.cpp Looper.cpp Looper.h EventQueue.cpp EventQueue.h Message.cpp Message.h)