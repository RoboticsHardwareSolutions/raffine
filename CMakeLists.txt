cmake_minimum_required(VERSION 3.28)
project(
        AffineTransformation
        VERSION 0.0.1
        LANGUAGES C
        DESCRIPTION "Affine transformation"
)

add_library(${PROJECT_NAME} STATIC affine_transformation.c)

target_include_directories(${PROJECT_NAME}
        PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR})
