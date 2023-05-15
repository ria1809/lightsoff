add_executable(test_box test_box.cpp )
add_test(NAME test_box  COMMAND test_box )
target_link_libraries(test_box PRIVATE gamelib Catch2::Catch2)
