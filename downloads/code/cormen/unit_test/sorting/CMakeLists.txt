
project( heap_sort )

include_directories( ${CORMEN_INCLUDE} )

add_executable( heap_sort HeapSort.cpp )

set( heap_sort-exe ${EXECUTABLE_OUTPUT_PATH}/heap_sort )
add_test( heap_sort1 ${heap_sort-exe} )
set_tests_properties( heap_sort1 PROPERTIES
    PASS_REGULAR_EXPRESSION "1,2,3,4,7,8,9,10,14,16,"
    )
