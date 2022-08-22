// This is the implementation of the ADT knightsTour.
// The interface is in the file "knightsTour.h".

#include <iostream>
#include <iomanip>
#include <cassert>
#include "knightsTour.h"

knightsTour::knightsTour(int size) : boardSize(size),
    rankMove{1, 2, 2, 1, -1, -2, -2, -1},
    fileMove{2, 1, -1, -2, -2, -1, 1, 2}
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

bool knightsTour::findMove(int rank, int file, int moves) 
{
    // Move through squares and backtrack if taken.
    if (moves == boardSize * boardSize) 
        return true;

    for (int i = 0; i < 8; i++) {
        int nextRank = i + rankMove[i];
        int nextFile = i + fileMove[i];

        if (canPlaceKnight(nextRank, nextFile)) {
            board[rank][file] = moves;
            if (findMove(nextRank, nextFile, moves))
                return true;
            board[nextRank][nextFile] = 0;
        }
    }
    return false;
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

    if (findMove(rank, file, 1))
        printTour();    // Tour found, print result.
}
