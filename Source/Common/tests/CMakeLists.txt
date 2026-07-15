add_executable(parse_test parse_test.cpp)
target_link_libraries(parse_test PRIVATE common)
add_test(NAME parse_test COMMAND parse_test)
