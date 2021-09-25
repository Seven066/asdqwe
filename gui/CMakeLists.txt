cmake_minimum_required(VERSION 3.10)

set(This gui)

find_package(Qt5 COMPONENTS Widgets REQUIRED)

add_library(${This}
    mainwindow.cpp
    chessboard.cpp
    figure.cpp)

target_link_libraries(${This} Qt5::Widgets)
