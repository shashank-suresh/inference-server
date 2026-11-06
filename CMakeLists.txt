cmake_minimum_required(VERSION 3.20)
project(inference-server LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(Threads REQUIRED)

add_executable(server src/main.cpp)
target_include_directories(server SYSTEM PRIVATE third_party)
target_link_libraries(server PRIVATE Threads::Threads)
