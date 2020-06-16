cmake_minimum_required (VERSION 3.16)

SET(CMAKE_CXX_STANDARD 20)
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wpedantic -Werror=pedantic -Wextra")

SET(PRJ_NAME "siguni")
project(${PRJ_NAME})

#add_custom_command(
#   OUTPUT
#      ${CMAKE_CURRENT_BINARY_DIR}/common/__fakefile.cpp 
#      ${CMAKE_CURRENT_BINARY_DIR}/common/version.cpp 
#    COMMAND  ${CMAKE_CURRENT_SOURCE_DIR}/common/version.sh ${CMAKE_CURRENT_SOURCE_DIR}/common ${CMAKE_CURRENT_BINARY_DIR}/common version.cpp
#)

find_package(GTest QUIET)

if(${GTest_FOUND})
add_subdirectory(gtest)
endif()


add_library(${PRJ_NAME}

   unit
   signal
   protocol
   managerbase

#   ${CMAKE_CURRENT_BINARY_DIR}/common/version.cpp 
)

#target_link_libraries (${PRJ_NAME} )
