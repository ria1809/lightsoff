
add_executable(test_box test_box.cpp)
add_test(NAME test_box  COMMAND test_box )
target_link_libraries(test_box PUBLIC Catch2::Catch2 threepp::threepp)
target_include_directories(test_box PUBLIC "${CMAKE_SOURCE_DIR}/include")