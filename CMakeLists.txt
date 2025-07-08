cmake_minimum_required(VERSION 3.10)
project(TaskManagerConsole)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)

set(SOURCES_APP
    src/CommandHandler.cpp
    src/Task.cpp
    src/FileManager.cpp
    src/TaskManager.cpp
    src/main.cpp
)

add_executable(TaskManagerConsole ${SOURCES_APP})