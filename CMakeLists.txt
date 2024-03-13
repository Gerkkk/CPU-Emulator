cmake_minimum_required(VERSION 3.27)
project(cpuemul)

set(CMAKE_CXX_STANDARD 20)

add_subdirectory(Stack)

add_executable(CPU
        CPUEmulator/Parser/parser.h
        CPUEmulator/Parser/parser.cpp
        CPUEmulator/Command/Command.h
        CPUEmulator/Command/Command.cpp
        CPUEmulator/exceptions/exceptions.h
        CPUEmulator/emul.cpp)

target_link_libraries(CPU PUBLIC Stack)
