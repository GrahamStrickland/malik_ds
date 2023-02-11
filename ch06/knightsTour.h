#ifndef KNIGHTS_TOUR_H 
#define KNIGHTS_TOUR_H

// This is the interface of the ADT knightsTour which simulates
// a knight's tour visiting every square in an nxn chessboard.

class knightsTour
{
public:
    knightsTour(int rank = 8, int file = 8);
        // Constructor with single argument.
        // Precondition: size > 0.
        // Postcondition: boardSize = size, board initialized
        //  to size x size matrix of zeros.
        
    ~knightsTour();
        //Destructor.

    bool canPlaceKnight(int rank, int file);
        // Function to check whether the given rank and file
        //  have already been visited.
        // Precondition: Returns true if board[rank][file] == 0;
        //  otherwise false.
        
    bool findMove(int rank, int file, int moves);
        // Function to find a move of from the current square in 
        //  the board.
        // Postcondition: Each square in the board assigned a
        //  number representing the order in the tour in which
        //  the square was visited.
        
    void printTour() const;
        // Function to print the knight's tour.
        // Postcondition: board printed to console.

    void beginTour(int rank, int file);
        // Function to begin the search for a knight's tour.
        // Precondition: rank and file are valid squares on
        //  this board.
        // Postcondition: Search for knight's tour started.
private: 
    static int s_NumMoves;
    int m_BoardRank;
    int m_BoardFile;
    int **m_Board;
    int *m_RankMove;
    int *m_FileMove; 
};
#endif // KNIGHTS_TOUR_H
