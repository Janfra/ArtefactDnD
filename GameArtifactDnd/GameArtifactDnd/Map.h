// Minimun y_size of the map has to be 16 until I add a way to automatically force it. Otherwise the stats won't show.

#define x_Size 16 
#define y_Size 16
#include <iostream>
#include <string>
using namespace std;

class Map {
public:
    Map();


    // Created a getGrid function to be able to display the map grid on the displayInfo for the Game Class
    string getGrid(short x, short y);


    // Emptyspace is no longer needed and even in the case of going back, now I have been using setw and setfill instead of emtpySpace as it was needed to align objects properly in
    // displayInfo function
    // int getEmptySpace();
    // void setEmptySpace(int size);

    // generateMap was the old version to cout the map that is not longer gonna be used but was used as base to create the displayInfo function
    // void generateMap();

    // Used a variable in private to set size and display it, then I decided that it wouldnt let me move around the map as it couldnt be used for a 2D grid and took it out and went for another
    // method
    //void setXSize(int size);
    //int getXSize();
    //int getYSize();
private:

    string grid[x_Size][y_Size];

    // Unnecessary variables, outdated
    // int emptySpace;
    // int ySize;
    // int xSize;
};