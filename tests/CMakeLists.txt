# files
file(GLOB TEST_FILES "./*.cpp" "./*/*.cpp")

# These tests need their own main
add_executable(${TEST_EXE} ${TEST_FILES})

