cmake_minimum_required(VERSION 3.24)

set(CMAKE_C_STANDARD 11)
project(
        raffine
        VERSION 0.0.1
        LANGUAGES C
        DESCRIPTION "Affine transformation"
)

add_library(${PROJECT_NAME} STATIC raffine.c)

if(UNIX AND NOT APPLE)
        target_link_libraries(${PROJECT_NAME} PRIVATE m)
endif()

target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

if(NOT ${CMAKE_SYSTEM_NAME} MATCHES Generic)
        add_subdirectory(test/runit)
        add_executable(${PROJECT_NAME}_test
                test/runit/src/runit.c
                raffine.c
                test/test.c)
        target_link_libraries(${PROJECT_NAME}_test PUBLIC runit ${PROJECT_NAME})
endif()

set(FILES_FOR_FORMATTING
        raffine.c
        raffine.h
        test/test.c
)

# clang-format
find_program(clang_format NAMES clang-format)

if(NOT clang_format)
        message(STATUS "Could not locate clang-format")
else()
        file(GLOB format_files ${FILES_FOR_FORMATTING})
        add_custom_target(raffine_format COMMAND ${clang_format} -i -fallback-style=none -style=file --verbose ${format_files})
endif()

# tests
enable_testing()
add_test(NAME ${PROJECT_NAME}_test COMMAND ${PROJECT_NAME}_test)
