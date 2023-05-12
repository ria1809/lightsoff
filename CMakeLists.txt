cmake_minimum_required(VERSION 3.15)
project(lightsoff)

set(CMAKE_CXX_STANDARD 17)

find_package(threepp CONFIG REQUIRED)
find_package(imgui CONFIG REQUIRED)
include_directories(include)
add_executable(lightsoff main.cpp Include/gridMap.h src/gridDisplayTest.cpp src/gridMap.cpp src/gridScene.cpp Include/gridScene.h Include/gridScene.h Include/play.h src/play.cpp)
target_link_libraries(lightsoff PRIVATE threepp::threepp imgui::imgui)