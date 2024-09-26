cmake_minimum_required(VERSION 3.5)

project(object-oriented LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(object-oriented main.cpp
    date.h date.cpp)

include(GNUInstallDirs)
install(TARGETS object-oriented
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
