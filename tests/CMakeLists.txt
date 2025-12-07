# GoogleTest Setup
include(FetchContent)

FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip
)

# Prevent gtest from forcing its own flags
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

FetchContent_MakeAvailable(googletest)

# Test Sources
set(TEST_SOURCES
    array_test.cpp
    test_main.cpp
)

add_executable(dsa_tests ${TEST_SOURCES})

target_include_directories(dsa_tests PRIVATE ${PROJECT_SOURCE_DIR}/include)
target_link_libraries(dsa_tests
    PRIVATE
        dsa_lib
        GTest::gtest
        GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(dsa_tests)
