cmake_minimum_required(VERSION 3.15)
project(SFMLTrafficLighter)

set(CMAKE_CXX_STANDARD 17)

set(SFML_INCLUDE_DIR "/home/bylaew/Downloads/SFML-2.5.1-Compiled/include")
set(SFML_LIBRARY_DIR "/home/bylaew/Downloads/SFML-2.5.1-Compiled/lib")
set(SFML_DIR "/home/bylaew/Downloads/SFML-2.5.1-Compiled/lib/cmake/SFML")

link_directories(SFML_LIBRARY_DIR)
include_directories(SFML_INCLUDE_DIR)

find_package(SFML 2.5.1 COMPONENTS system window graphics network audio)

if(SFML_FOUND)
    message(STATUS "SFML_INCLUDE_DIR: ${SFML_INCLUDE_DIR}")
    message(STATUS "SFML_LIBRARIES: ${SFML_LIBRARIES}")
    message(STATUS "SFML_VERSION: ${SFML_VERSION}")
endif()

add_executable(SFMLTrafficLighter main.cpp Car.h Car.cpp Lighter.h Lighter.cpp)
target_link_libraries (SFMLTrafficLighter sfml-graphics sfml-window sfml-system)