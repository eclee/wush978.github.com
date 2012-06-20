cmake_minimum_required(VERSION 2.8)

set( CORMEN_INCLUDE ${CMAKE_CURRENT_SOURCE_DIR} )

add_subdirectory( sorting )

if(ENABLE_TEST)
    enable_testing()
    add_subdirectory(unit_test)
endif()
