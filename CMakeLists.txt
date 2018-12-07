cmake_minimum_required(VERSION 3.5)

include_directories(include)

add_library(pairs_and_triples src/pairs_and_triples.cpp)

add_executable(day_one src/first_exercise.cpp)
add_executable(day_two src/part_two.cpp)
target_link_libraries(day_two pairs_and_triples)


add_subdirectory(tests)

