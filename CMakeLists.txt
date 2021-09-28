cmake_minimum_required(VERSION 3.10)

set(This asdqwe)
project(${This} VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

find_package(Qt5 COMPONENTS Widgets REQUIRED)

add_subdirectory(gui)
add_subdirectory(network)

add_executable(${This}
    main.cpp
    mainwindow.cpp
    imgs.qrc
)

target_link_libraries(${This}
    Qt5::Widgets
    gui
    network)
