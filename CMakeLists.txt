cmake_minimum_required(VERSION 3.10)

project(practiceGL)

if(POLICY CMP0074)
    cmake_policy(SET CMP0074 NEW)
endif()

set(CMAKE_CXX_STANDARD 17)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)

set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/deps)
set(GLAD_DIR ${PROJECT_SOURCE_DIR}/deps/glad)

find_package(GLFW REQUIRED)

include_directories(${GLFW_INCLUDE_DIR})
include_directories(${GLAD_DIR}/include)
include_directories(${PROJECT_SOURCE_DIR})

add_library(
    glad
    ${GLAD_DIR}/src/glad.c
)
set_target_properties(glad PROPERTIES FOLDER "Grad")

add_library(
    shader
    shader.h
    shader.cpp
)
set_target_properties(shader PROPERTIES FOLDER "PracticeGL")

add_library(
    camera
    camera.h
    camera.cpp
)
set_target_properties(camera PROPERTIES FOLDER "PracticeGL")

add_executable(
    glTest
    main.cpp
    privdef.h
)
target_link_libraries(
    glTest
    glad
    ${GLFW_LIBRARIES}
    shader
    camera
)
set_target_properties(glTest PROPERTIES FOLDER "PracticeGL")