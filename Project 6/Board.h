//
//  Board.h
//  Bunco
//
//  Created by Howard Stahl on 1/27/17.
//  Copyright © 2017 Howard Stahl. All rights reserved.
//

#ifndef Board_h
#define Board_h
#include "BoardRow.h"

namespace cs31
{

    // CS 31 students have been provided this class to represent
    // a Bunco Board.  Each Board is made up of an array of BoardRow.
    // The display( ) method is used by the Bunco game to print the
    // current state of the game.  Each Board knows the current round
    // in play.  Each Board gets told when either the human player wins
    // the round or the computer player wins the round.  Given the
    // array of BoardRow, this class can count up how many rounds each
    // player has won.
    // CS 31 students need to complete the TODO portions of this class
    class Board
    {
    public:
        Board();
        void setCurrentRound( int round );          //sets the current round
        void markHumanAsWinner();                   //sets the human as the round winner
        void markComputerAsWinner();                //sets the human as the round winner
        int countUpComputerRoundWins( ) const;      //determines how many round the computer has won
        int countUpHumanRoundWins( ) const;         //determines how many rounds human has won
        int getCurrentRound() const;
        std::string display( ) const;
    private:
        BoardRow mBoardRow[ 7 ];  // elements 1-6, ignoring spot 0,
                                  // are used for rounds 1-6
        int      mRound;          // the current round of play
    };
    
}

#endif /* Board_h */
