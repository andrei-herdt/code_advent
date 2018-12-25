cmake_minimum_required(VERSION 3.5)

include_directories(include)

add_library(pairs_and_triples src/pairs_and_triples.cpp)
add_library(find_duplicate src/find_duplicate.cpp)
add_library(day_three_utils src/day_three_utils.cpp)
add_library(day_four_utils src/day_four_utils.cpp)
add_library(day_five_utils src/day_five_utils.cpp)

add_executable(day_one src/first_exercise.cpp)

add_executable(day_two src/part_two.cpp)
target_link_libraries(day_two pairs_and_triples find_duplicate)

add_executable(day_three src/day_three.cpp)
target_link_libraries(day_three day_three_utils)

add_executable(day_four src/day_four.cpp)
target_link_libraries(day_four day_four_utils)

add_executable(day_five src/day_five.cpp)
target_link_libraries(day_five day_five_utils)

add_subdirectory(tests)

