// This is the implementation of the ADT knightsTour.
// The interface is in the file "knightsTour.h".

#include "knightsTour.h"
#include <cassert>
#include <iomanip>
#include <iostream>

int knightsTour::s_NumMoves = 8;

knightsTour::knightsTour(int rank, int file)
    : m_BoardRank(rank), m_BoardFile(file) {
  m_RankMove = new int[s_NumMoves];
  m_FileMove = new int[s_NumMoves];
  for (int i = 0; i < s_NumMoves; i++) {
    m_RankMove[i] = (i / 2) - (i > 3 ? 1 : 2);
    m_FileMove[i] =
        (std::abs(m_RankMove[i]) == 1 ? 2 : 1) * (i % 2 == 0 ? 1 : -1);
  }

  m_Board = new int *[m_BoardRank];
  for (int rank = 0; rank < m_BoardRank; rank++) {
    m_Board[rank] = new int[m_BoardFile];
    for (int file = 0; file < m_BoardFile; file++) {
      m_Board[rank][file] = 0;
    }
  }
}

knightsTour::~knightsTour() {
  delete[] m_RankMove;
  delete[] m_FileMove;

  for (int i = 0; i < m_BoardRank; i++)
    delete[] m_Board[i];
  delete[] m_Board;
}

bool knightsTour::canPlaceKnight(int rank, int file) {
  if (rank >= 0 && rank < m_BoardRank && file >= 0 && file < m_BoardFile &&
      m_Board[rank][file] == 0)
    return true;
  else
    return false;
}

bool knightsTour::findMove(int rank, int file, int moves) {
  // Return true if all squares on board used.
  if (moves == m_BoardRank * m_BoardFile)
    return true;

  // Create variables for next move.
  int nextRank, nextFile;

  // Find moves and backtrack if no moves available.
  for (int i = 0; i < s_NumMoves; i++) {
    nextRank = rank + m_RankMove[i];
    nextFile = file + m_FileMove[i];

    if (canPlaceKnight(nextRank, nextFile)) {
      m_Board[nextRank][nextFile] = moves + 1;
      if (findMove(nextRank, nextFile, moves + 1))
        return true;
      else
        m_Board[nextRank][nextFile] = 0;
    }
  }
  return false; // No moves available, return false.
}

void knightsTour::printTour() const {
  std::cout << '\n';
  for (int rank = 0; rank < m_BoardRank; rank++) {
    for (int file = 0; file < m_BoardFile; file++)
      std::cout << std::setw(3) << m_Board[rank][file];
    std::cout << '\n';
  }
  std::cout << '\n';
}

void knightsTour::beginTour(int rank, int file) {
  assert(canPlaceKnight(rank, file));

  m_Board[rank][file] = 1;

  if (findMove(rank, file, 1))
    printTour(); // Tour found, print result.
  else
    std::cout << "No tour exists starting at rank " << rank << ", file " << file
              << ".\n";
}
