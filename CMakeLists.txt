cmake_minimum_required(VERSION 3.10)

project(glMisc)

cmake_policy(SET CMP0074 NEW)

set(CMAKE_CXX_STANDARD 17)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)

set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/deps)
set(GLAD_DIR ${PROJECT_SOURCE_DIR}/deps/glad)

find_package(GLFW REQUIRED)

include_directories(${GLFW_INCLUDE_DIR})
include_directories(${GLAD_DIR}/include)
include_directories(${PROJECT_SOURCE_DIR})

add_library(
    shader
    shader.h
    shader.cpp
)
set_target_properties(shader PROPERTIES FOLDER "practiceGL")

add_executable(
    glTest
    main.cpp
    ${GLAD_DIR}/src/glad.c
)

target_link_libraries(
    glTest
    ${GLFW_LIBRARIES}
    shader
)
set_target_properties(glTest PROPERTIES FOLDER "practiceGL")