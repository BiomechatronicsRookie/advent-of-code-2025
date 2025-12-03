cmake_minimum_required(VERSION 3.11)
project(advent_of_calendar_2025)

set(SOURCES ./src/day1/day1.cpp ./src/day1/Wheel.cpp ./inc/day1/Wheel.h)

add_executable(day1 ${SOURCES})

target_include_directories(day1 PUBLIC ./inc/day1)

set_target_properties(day1 PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})