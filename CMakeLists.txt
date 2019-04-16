cmake_minimum_required(VERSION 3.10)
project(EventLoopDemo)

set(CMAKE_CXX_STANDARD 14)
set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)
add_executable(EventLoopDemo main.cpp looper.cpp looper.h messageQueue.cpp messageQueue.h message.cpp message.h util.cpp util.h)
target_link_libraries(EventLoopDemo Threads::Threads)