#include <iostream>
#include "gridMap.h"
#include "threepp/threepp.hpp"
#include <random>
#include "gridScene.h"
#include "mouseEvent.h"
#define LOG_INFO(msg) std::cout << "[INFO] " << msg << std::endl;

using namespace threepp;
using namespace std;

int main() {
    BoxScene BoxScene;
    BoxScene.run();



            /*int i,j;
            gridMap grid; // printing out after this line will print out the grid with values assigned 0
            grid.initializeGrid();// function for assigning 0 and 1 randomly
            grid.display();// printing out after this line will print out the grid with random assignments of 0 and 1
            std::cout << "Enter row and column (0-4) to toggle the light: ";

            while (cin >> i >> j) {
                grid.toggle(i, j);
                grid.display();
                grid.win();
            }*/

            return 0;
        }