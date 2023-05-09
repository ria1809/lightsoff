#include "gridMap.h"

gridMap::gridMap() { //cannot have return type as it is a constructor
   moves=0;
   grid.resize(SIZE, vector<int>(SIZE, false));
}
void gridMap::display() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
    cout<< "Moves used:"<<moves<<std::endl;
}
void gridMap::initializeGrid() {
    srand(time(NULL));// the time(NULL) is a seed for randomising the number, it allows the function to assign different values each time its ran as null pointers dont store it in the memory
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            grid[i][j]= rand()%2==0; // sets random values of 0 and 1
        }
    }
}

void gridMap::toggle(int& i, int& j) { //using references here allows us to directly make changes to i and j from inside the function and have it impact the calling code
    moves++;
    if (i >= 0 && i < SIZE && j >= 0 && j < SIZE) {
        grid[i][j] = !grid[i][j]; //toggle selected light
        if (i > 0)
            grid[i - 1][j] = !grid[i - 1][j];
        if (i < SIZE - 1)
            grid[i + 1][j] = !grid[i + 1][j];
        if (j > 0)
            grid[i][j - 1] = !grid[i][j - 1];
        if (j < SIZE - 1)
            grid[i][j + 1] = !grid[i][j + 1];
    }
    else {
        std::cout << "Invalid input. Please try again." << std::endl;
    }
}

void gridMap::win() {
    bool allZero = true; // initial condition set to 0( this should be met)
    for (int i = 0; i < grid.size(); i++)/* iterates over each row in the grid*/ {
        for (int j = 0; j < grid[i].size(); j++) /* iterates over each element in the grid*/ {
            if (grid[i][j] != 0) {
                allZero = false; // Set the flag to false if any element is non-zero
                break; // Exits the inner loop
            }
        }
        if (!allZero) {
            cout<< "Enter row and column (0-4) to toggle the light:"; // what happens if allZero is not met
            break; // Exits the outer loop and allows the main code to continue
        }
    }
    if (allZero) {
        cout << "Congratulations, you got it!" << endl; // if allZero is met
        return; //stops the code here
    }
}


//
// Created by Ria Sharma on 04/05/23.
//
