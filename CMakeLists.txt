cmake_minimum_required(VERSION 3.10)

# Set the project name
project(ADVANCED_PROGRAMMING_TASK_1)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 14)

# Explicitly Set the source files (you can switch this to wildcard if needed)
set(SOURCES
        src/main.cpp
        src/DrawableGameComponent.cpp
        src/GameComponent.cpp
        src/Game.cpp
    )

# Create the executable
add_executable(GameApp ${SOURCES})

# Associate include directories with the target
target_include_directories(GameApp PRIVATE ${PROJECT_SOURCE_DIR}/include)
