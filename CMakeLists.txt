cmake_minimum_required(VERSION 3.10.0)
project(change_generator VERSION 0.1.0 LANGUAGES C)

add_executable(cg main.c src/change.c)

target_include_directories(cg PRIVATE include)

include(CTest)
enable_testing()

add_subdirectory(tests)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)