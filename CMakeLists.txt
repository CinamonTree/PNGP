cmake_minimum_required(VERSION 3.16)

set(PROJECT_NAME_GLOBAL PNGP)

project(${PROJECT_NAME_GLOBAL} VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include(FetchContent)

FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/heads/main.zip
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_library(${PROJECT_NAME_GLOBAL}_headers INTERFACE)
target_include_directories(${PROJECT_NAME_GLOBAL}_headers INTERFACE src/include)

# tests
file(GLOB_RECURSE TEST_SOURCES CONFIGURE_DEPENDS
    "${CMAKE_CURRENT_SOURCE_DIR}/tests/*.cpp"
)

add_executable(${PROJECT_NAME_GLOBAL}_tests ${TEST_SOURCES})

target_link_libraries(${PROJECT_NAME_GLOBAL}_tests
    PRIVATE
    ${PROJECT_NAME_GLOBAL}_headers
    GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(${PROJECT_NAME_GLOBAL}_tests)
