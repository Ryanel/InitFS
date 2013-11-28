#Cmake build file

CMAKE_MINIMUM_REQUIRED(VERSION 2.8)
PROJECT(initfs)
add_definitions(-O2)

##INITFSCK
file(GLOB C_SRCS_INITFSCK initfsck/*.c)
add_executable(initfsck ${C_SRCS_INITFSCK})