cmake_minimum_required(VERSION 3.5)

add_executable(advent src/first_exercise.cpp)

target_link_libraries(advent part_two)

add_subdirectory(tests)

