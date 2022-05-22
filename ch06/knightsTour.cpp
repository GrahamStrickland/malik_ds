// This is the implementation of the ADT knightsTour.
// The interface is in the file "knightsTour.h".

#include <iostream>
#include <cassert>
#include "knightsTour.h"

knightsTour::knightsTour(int size) : boardSize(size)
{
    board = new int[boardsize];

    for (int rank = 0; rank < boardSize; rank++)
        for (int file = 0; file < boardSize; file++)
            board[rank][file] = 0;
}

bool knightsTour::canPlaceKnight(int rank, int file)
{
    if (rank >= 0 && rank < boardSize && 
            file >= 0 && file < boardSize && 
            board[rank][file] == 0)
        return true;
    else return false;
}

void knightsTour::findMove(int rank, int file, int moves)
{
    // Move knight to given position.
    board[rank][file] = moves;

    // Move through squares and backtrack if taken.
    while (moves < size * size) {
        if (canPlaceKnight(rank+2, file+1)) {
            moves++;
            findMove(rank+2, file+1);
        } else if (canPlaceKnight(rank+2, file-1) {
            moves++;
            findMove(rank+1, file-1);
        } else if (canPlaceKnight(rank+1, file+2) {
            moves++;
            findMove(rank+1, file+1);
        } else if (canPlaceKnight(rank+1, file-2) {
            moves++;
            findMove(rank+1, file+1);
        } else if (canPlaceKnight(rank-2, file+1) {
            moves++;
            findMove(rank+1, file+1);
        } else if (canPlaceKnight(rank-2, file-1) {
            moves++;
            findMove(rank+1, file+1);
        } else if (canPlaceKnight(rank-1, file+2) {
            moves++;
            findMove(rank+1, file+1);
        } else if (canPlaceKnight(rank-1, file-2) {
            moves++;
            findMove(rank+1, file+1);
        } else {    // Search unsuccessful.
            cout << "Cannot find a tour starting from this position.";
            printTour();
        }
    }

    printTour();    // Tour found, print result.
}

void knightsTour::printTour()
{
    for (int rank = 0; rank < boardSize; rank++) {
        for (int file = 0; file < boardSize; file++)
            cout << board[rank][file] << " ";
        cout << endl;
    cout << endl;
}

void knightsTour::beginTour(int rank, int file)
{
    assert(canPlaceKnight(rank, file));

    findMove(rank, file, 1);
}
