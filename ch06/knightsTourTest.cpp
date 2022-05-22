// This is a driver program to test the ADT knightsTour
// that simulates a search for a knight's tour around a
// chessboard of given size, starting at a given square.

#include <iostream>
#include "knightsTour.h"

int main() {
    knightsTour tour(5);

    tour.beginTour(0,0);

    return 0;
}
