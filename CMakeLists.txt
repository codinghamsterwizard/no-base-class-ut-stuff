cmake_minimum_required(VERSION 3.15 FATAL_ERROR)

project(no_base_class_ut_stuff VERSION 0.0.1 LANGUAGES CXX)

include(FetchContent)
include(GoogleTest)

FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG        release-1.12.1)

FetchContent_MakeAvailable(googletest)

FetchContent_Declare(
    fmtlib
    GIT_REPOSITORY https://github.com/fmtlib/fmt.git
    GIT_TAG        9.1.0)

FetchContent_MakeAvailable(fmtlib)

enable_testing()

add_executable(serialization_test
    test/serialization_test.cpp)

target_link_libraries(serialization_test
PRIVATE
    GTest::gtest_main)

gtest_discover_tests(serialization_test)

add_library(byte_stream
    src/int_string_message.h
    src/message_builder.h
    src/message_deserializer.cpp
    src/message_deserializer.h
    src/message_id.h
    src/message_input_stream.h
    src/message_output_stream.h
    src/message_serializer.cpp
    src/message_serializer.h
    src/mockable.h
    src/return_code.h)

add_executable(no_base_class_ut_stuff src/main.cpp)

target_link_libraries(no_base_class_ut_stuff
PRIVATE
    fmt::fmt
    byte_stream)

target_compile_features(no_base_class_ut_stuff PRIVATE cxx_std_14)
