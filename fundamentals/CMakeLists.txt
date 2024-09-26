cmake_minimum_required(VERSION 3.5)

project(fundamentals LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(fundamentals main.cpp)

include(GNUInstallDirs)
install(TARGETS fundamentals
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
