//
//  Board.cpp
//  Bunco
//
//  Created by Howard Stahl on 1/27/17.
//  Copyright © 2017 Howard Stahl. All rights reserved.
//

#include "Board.h"


namespace cs31
{
    Board::Board() : mRound( 0 )
    {
        // initialize each BoardRow
        for (int i = 1; i <= 6; i++)
        {
            mBoardRow[ i ].setRound( i );
        }
    }
    
    void Board::setCurrentRound( int round )
    {
        // unset the current board row
        if (mRound >= 0 && mRound <= 6)
            mBoardRow[ mRound ].setCurrentRound( false );
        mRound = round;
        // set the current board row
        if (mRound >=0 && mRound <=6)
            mBoardRow[ mRound ].setCurrentRound(true);
    }
    
    void Board::markHumanAsWinner()                     //sets the human to have won the specific board row
    {
        mBoardRow[ mRound ].setHumanAsWinner();
    }
    
    void Board::markComputerAsWinner()
    {
        mBoardRow[ mRound ].setComputerAsWinner();      //sets the computer to have won the specific board row
    }
    
    // stringify the Board
    std::string Board::display( ) const
    {
        std::string s = "\t\t  Bunco Game\n\tHuman\t\t\tComputer\n";
        
        for( int i = 1; i <= 6; i++)
        {
            s += mBoardRow[ i ].display() + "\n";
        }
        
        return( s );
    }
    
    int Board::countUpHumanRoundWins( ) const                   //counts up the round wins for human
    {
        int humanWins = 0;
        for (int i = 0; i <= 6; i++){
            bool p = mBoardRow[ i ].didHumanWin();
            if (p == true){
                humanWins++;
        }
    }
        return( humanWins );
}

    int Board::countUpComputerRoundWins( ) const                //counts up the round wins for computer
    {
        int compWins = 0;
        for (int i = 0; i <= 6; i++){
            bool p = mBoardRow[ i ].didComputerWin();
            if (p == true){
                compWins++;
        }
    }
        return( compWins );
    }
    
    int Board::getCurrentRound() const
    {
    return (mRound);
    }
}
