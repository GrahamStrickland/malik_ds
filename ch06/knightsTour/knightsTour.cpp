// This is the implementation of the ADT knightsTour.
// The interface is in the file "knightsTour.h".

#include <iostream>
#include <iomanip>
#include <cassert>
#include "knightsTour.h"

knightsTour::knightsTour(int size) : boardSize(size)
{
    *board = new int[boardSize];

    clearBoard();
}

void knightsTour::clearBoard()
{
    for (int rank = 0; rank < boardSize; rank++) {
        board[rank] = new int[boardSize];
        for (int file = 0; file < boardSize; file++) {
            board[rank][file] = 0;
        }
    }
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
    while (moves < boardSize * boardSize) {
        if (canPlaceKnight(rank+2, file+1)) {
            moves++;
            findMove(rank+2, file+1, moves);
        } else if (canPlaceKnight(rank+2, file-1)) {
            moves++;
            findMove(rank+2, file-1, moves);
        } else if (canPlaceKnight(rank+1, file+2)) {
            moves++;
            findMove(rank+1, file+2, moves);
        } else if (canPlaceKnight(rank+1, file-2)) {
            moves++;
            findMove(rank+1, file-2, moves);
        } else if (canPlaceKnight(rank-2, file+1)) {
            moves++;
            findMove(rank-2, file+1, moves);
        } else if (canPlaceKnight(rank-2, file-1)) {
            moves++;
            findMove(rank-2, file-1, moves);
        } else if (canPlaceKnight(rank-1, file+2)) {
            moves++;
            findMove(rank-1, file+2, moves);
        } else if (canPlaceKnight(rank-1, file-2)) {
            moves++;
            findMove(rank-1, file-2, moves);
        } else {    // Search unsuccessful, backtrack.
            board[rank][file] = 0;
            moves--;
            break;
        }
    }
}

void knightsTour::printTour() const
{
    std::cout << '\n';
    for (int rank = 0; rank < boardSize; rank++) {
        for (int file = 0; file < boardSize; file++)
            std::cout << std::setw(3) << board[rank][file];
        std::cout << '\n';
    }
    std::cout << '\n';
}

void knightsTour::beginTour(int rank, int file)
{
    assert(canPlaceKnight(rank, file));

    findMove(rank, file, 1);

    printTour();    // Tour found, print result.
}
