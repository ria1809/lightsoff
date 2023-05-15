set(sources
        "gridScene.cpp"
        )

add_library(gamelib ${sources})
target_link_libraries(gamelib PUBLIC threepp::threepp)
target_include_directories(gamelib PUBLIC "${CMAKE_SOURCE_DIR}/include")