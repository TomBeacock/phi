cmake_minimum_required(VERSION 3.19)

project(phi LANGUAGES C CXX)

add_executable(phi)
target_sources(
    phi
    PRIVATE "src/main.cpp"
            "src/commands/command.hpp"
            "src/commands/command.cpp"
            "src/commands/run.hpp"
            "src/commands/run.cpp"
)

set_target_properties(phi PROPERTIES CXX_STANDARD 23 CMAKE_STANDARD_REQUIRED ON)
