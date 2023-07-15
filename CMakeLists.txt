cmake_minimum_required(VERSION 3.12.0)



# here we specify that the project is C language only, so the default
# C compiler on the system will be used
project(myprogram C)

list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake/cmocka)
if (UNIT_TESTING)
     find_package(cmocka 1.1.0 REQUIRED)
     include(AddCMockaTest)
     add_subdirectory(tests)
endif()

add_executable(myprogram main.c)

