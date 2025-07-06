cmake_minimum_required(VERSION 3.10.0)
project(WorldsGeneration VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt5 COMPONENTS Widgets OpenGL REQUIRED)
find_package(OpenGL REQUIRED)

INCLUDE_DIRECTORIES(
    ./src/Algorithms/
    ./src/Vizualization/
    ./src/Types/
)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON) 
set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(PROJECT_SOURCES
    ./main.cpp
    ./src/Vizualization/MainWindow.cpp
)

add_executable(WorldsGeneration ${PROJECT_SOURCES})

target_link_libraries(${PROJECT_NAME}
    Qt5::Widgets
    Qt5::OpenGL
    OpenGL::GL
)
