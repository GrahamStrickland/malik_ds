// This is a driver program to test the ADT knightsTour
// that simulates a search for a knight's tour around a
// chessboard of given size, starting at a given square.

#include "knightsTour.h"
#include <iostream>

int main() {
  knightsTour tour(4, 5);

  tour.beginTour(0, 0);

  return 0;
}
