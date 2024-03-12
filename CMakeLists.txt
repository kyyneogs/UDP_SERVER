cmake_minimum_required(VERSION 3.22)

project(
    UDP_SERVER
    LANGUAGES CXX
    VERSION 0.0.1
)

file(GLOB SOURCES ${CMAKE_SOURCE_DIR}/dev/src/*.cpp)

add_executable(Udp_Server ${SOURCES})

target_include_directories(Udp_Server PUBLIC ${CMAKE_SOURCE_DIR}/dev/include)