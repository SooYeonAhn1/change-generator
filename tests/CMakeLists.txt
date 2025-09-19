add_executable(cg_tests tests.c ../src/change.c)

add_test(NAME CUnitTests COMMAND cg_tests)