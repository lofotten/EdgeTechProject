cmake_minimum_required(VERSION 4.0)

project(EdgeTechProject)


add_executable(EdgeTechProject
    ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp 
)


target_include_directories(EdgeTechProject PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)