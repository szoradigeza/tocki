cmake_minimum_required(VERSION 3.12.0)

# here we specify that the project is C language only, so the default
# C compiler on the system will be used
project(myprogram C)

add_executable(myprogram main.c)