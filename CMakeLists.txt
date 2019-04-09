cmake_minimum_required(VERSION 3.13)
project(EventLoopDemo)

set(CMAKE_CXX_STANDARD 14)

add_executable(EventLoopDemo main.cpp Looper.cpp Looper.h EventLoop.cpp EventLoop.h Message.cpp Message.h)