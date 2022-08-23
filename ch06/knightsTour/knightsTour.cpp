// This is the implementation of the ADT knightsTour.
// The interface is in the file "knightsTour.h".

#include <iostream>
#include <iomanip>
#include <cassert>
#include "knightsTour.h"

int knightsTour::s_NumMoves = 8;

knightsTour::knightsTour(int size) : m_BoardSize(size)
{
    m_RankMove = new int[s_NumMoves];
    m_FileMove = new int[s_NumMoves];
    for (int i = 0; i < s_NumMoves; i++) {
        m_RankMove[i] = (i / 2) - 2;
        m_FileMove[i] = (std::abs(m_RankMove[i]) == 1 ? 2 : 1) * (i % 2 == 0 ? 1 : -1);
    }

    *m_Board = new int[m_BoardSize];

    clearBoard();
}

void knightsTour::clearBoard()
{
    for (int rank = 0; rank < m_BoardSize; rank++) {
        m_Board[rank] = new int[m_BoardSize];
        for (int file = 0; file < m_BoardSize; file++) {
            m_Board[rank][file] = 0;
        }
    }
}

bool knightsTour::canPlaceKnight(int rank, int file)
{
    if (rank >= 0 && rank < m_BoardSize && 
            file >= 0 && file < m_BoardSize && 
            m_Board[rank][file] == 0)
        return true;
    else return false;
}

bool knightsTour::findMove(int rank, int file, int moves) 
{
    // Return true if all squares on board used.
    if (moves == m_BoardSize * m_BoardSize) 
        return true;

    // Create variables for next move.
    int nextRank, nextFile;

    // Find moves and backtrack if no moves available.
    for (int i = 0; i < s_NumMoves; i++) {
        nextRank = i + m_RankMove[i];
        nextFile = i + m_FileMove[i];

        if (canPlaceKnight(nextRank, nextFile)) {
            m_Board[nextRank][nextFile] = ++moves;
            if (findMove(nextRank, nextFile, moves))
                return true;
            m_Board[nextRank][nextFile] = 0;
        }
    }
    return false;   // No moves available, return false.
}

void knightsTour::printTour() const
{
    std::cout << '\n';
    for (int rank = 0; rank < m_BoardSize; rank++) {
        for (int file = 0; file < m_BoardSize; file++)
            std::cout << std::setw(3) << m_Board[rank][file];
        std::cout << '\n';
    }
    std::cout << '\n';
}

void knightsTour::beginTour(int rank, int file)
{
    assert(canPlaceKnight(rank, file));

    if (findMove(rank, file, 1))
        printTour();    // Tour found, print result.
    else
        std::cout << "No tour exists starting at rank " << rank
                  << ", file " << file << ".\n";
}
