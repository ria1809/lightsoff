#include <iostream>
#include <vector>
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

class gridMap {
private:
    static const int SIZE = 5;  // Size of the grid
    vector<vector<int>> grid; // establishing a vector of vectors (creates a 2D grid)
    inline static unsigned int moves=0;
public:
    // Constructor
    gridMap();

    // Display the grid, displays every single term of the grid onto the console
    void display() ;

    //Initializes the grid
    void initializeGrid();

    // Turns on adjacent lights with edge detection
    void toggle (int& i, int& j);

    //winning condition for the game
    void win();

};