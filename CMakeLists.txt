#CMake v3.11+ should be used
cmake_minimum_required(VERSION 3.11-3.18)

project(
    bailando-basic-web
    VERSION 0.0.1
    DESCRIPTION "My library for basic c++ web functionality")

message(STATUS "Starting build of ${PROJECT_NAME}")

#Requires installing libssl-dev
#Requires installing libcurl4-gnutls-dev
add_library(${PROJECT_NAME} INTERFACE)
#add_library(${PROJECT_NAME} STATIC src/SimpleWebTest.cpp)
#add_executable(${PROJECT_NAME} src/main.cpp src/SimpleWebTest.cpp)

add_subdirectory(dependencies)

#target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR}/include)
target_include_directories(${PROJECT_NAME} INTERFACE ${PROJECT_SOURCE_DIR}/include)
#target_link_libraries(${PROJECT_NAME} PRIVATE curl nlohmann_json::nlohmann_json)
target_link_libraries(${PROJECT_NAME} INTERFACE curl nlohmann_json::nlohmann_json)

#Use c++ 20
#target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_20)
target_compile_features(${PROJECT_NAME} INTERFACE cxx_std_20)