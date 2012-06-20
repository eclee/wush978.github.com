project( heap-unit )

include_directories( ${CORMEN_INCLUDE} )

add_executable( heap-unit Heap.cpp )

set( heap-unit-exe ${EXECUTABLE_OUTPUT_PATH}/heap-unit )
add_test( heap-unit1 ${heap-unit-exe} )
set_tests_properties( heap-unit1 PROPERTIES
    PASS_REGULAR_EXPRESSION "27,17,10,16,13,9,1,5,7,12,4,8,3,0"
    )