cmake_minimum_required(VERSION 3.5)

configure_file(CMakeLists.txt.in googletest-download/CMakeLists.txt)
execute_process(COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" .
  RESULT_VARIABLE result
  WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/tests/googletest-download )
if(result)
  message(FATAL_ERROR "CMake step for googletest failed: ${result}")
endif()
execute_process(COMMAND ${CMAKE_COMMAND} --build .
  RESULT_VARIABLE result
  WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/tests/googletest-download )
if(result)
  message(FATAL_ERROR "Build step for googletest failed: ${result}")
endif()

add_subdirectory(${CMAKE_BINARY_DIR}/googletest-src
                 ${CMAKE_BINARY_DIR}/googletest-build
                 EXCLUDE_FROM_ALL)

add_executable(tests
    tests.cpp
    tests_part_two.cpp
    tests_day_three.cpp
    tests_day_four.cpp
    tests_day_five.cpp
    tests_day_six.cpp
    tests_day_seven.cpp
    tests_day_8.cpp
    )

add_test(NAME tests COMMAND tests)

target_link_libraries(tests PRIVATE gmock_main pairs_and_triples find_duplicate day_three_utils day_four_utils day_five_utils)
