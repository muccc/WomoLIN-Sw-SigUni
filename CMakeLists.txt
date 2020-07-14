cmake_minimum_required (VERSION 3.16)

SET(CMAKE_CXX_STANDARD 20)
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror -Wpedantic -Werror=pedantic -Wextra")

SET(PRJ_NAME "siguni")
project(${PRJ_NAME})

find_package(GTest QUIET)

if(${GTest_FOUND})
add_subdirectory(gtest)
endif()


add_library(${PRJ_NAME}

   unit.cpp
   signal.cpp
   hal.cpp
   protocol.cpp
   managerbase.cpp
   additionals.cpp
   helper.cpp

)
