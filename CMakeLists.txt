cmake_minimum_required(VERSION 3.14)
project(ICPCPrep)

# GoogleTest requires at least C++14
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_POLICY_NEW)
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/530d5c8c84abd2a46f38583ee817743c9b3a42b4.zip
  DOWNLOAD_EXTRACT_TIMESTAMP TRUE
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(
  CP-Implementations
  CP-Algorithms/Implementations/implementations.cpp
)
target_link_libraries(
  CP-Implementations
  GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(CP-Implementations)