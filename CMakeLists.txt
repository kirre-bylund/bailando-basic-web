#CMake v3.11+ should be used
cmake_minimum_required(VERSION 3.11-3.18)

project(
    bailando-basic-web
    VERSION 0.0.1
    DESCRIPTION "My library for basic c++ web functionality")

message(STATUS "Starting build of ${PROJECT_NAME}")

add_executable(${PROJECT_NAME} src/main.cpp)

add_subdirectory(lib)

target_link_libraries(${PROJECT_NAME}
    PRIVATE basic_include)

#Use c++ 20
target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_20)