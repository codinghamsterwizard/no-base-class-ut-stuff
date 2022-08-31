cmake_minimum_required(VERSION 3.15 FATAL_ERROR)

project(no-base-class-ut-stuff VERSION 0.0.1 LANGUAGES CXX)

include(FetchContent)

FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG        release-1.12.1)

FetchContent_MakeAvailable(googletest)

add_executable(no-base-class-ut-stuff
    src/main.cpp)

target_compile_features(no-base-class-ut-stuff PRIVATE cxx_std_11)
