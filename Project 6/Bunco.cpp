//
//  Bunco.cpp
//  Bunco
//
//  Created by Howard Stahl on 1/27/17.
//  Copyright © 2017 Howard Stahl. All rights reserved.
//

#include "Bunco.h"
#include <iostream>

namespace cs31
{
    Bunco::Bunco() : mRound( 1 )
    {
        setRound( mRound );
    }
    
    // stringify the game by stringifying the board
    std::string Bunco::display( std::string msg ) const
    {
        using namespace std;
        std::string s = mBoard.display();
        s = s + msg;
        
        if (gameIsOver())
        {
            if (determineGameOutcome() == TIEDGAME)
            {
                s = s + "\n\t\tBunco wound up tied!\n";
            }
            else if (determineGameOutcome() == HUMANWONGAME)
            {
                s = s + "\n\t\tyou won Bunco!\n";
            }
            else
            {
                s = s + "\n\t\tyou lost Bunco!\n";
            }
        }
        return( s );
    }
    
    // set the current round of play, notifying the board and each
    // player of the current round
    void Bunco::nextRound( )
    {
        // prevent walking off the edge of the Board...
       if (mRound <= 5)
       {
          mRound = mRound + 1;
          setRound( mRound );
       }
    }


    // set the current round of play, notifying the board and each
    // player of the current round
    void Bunco::setRound( int round )
    {
        mRound = round;
        mBoard.setCurrentRound( round );
        mHuman.setRound(round);
        mComputer.setRound(round);
    }
    
    int Bunco::humanPlay( )                 //randomly rolls the human player's die and return what was rolled
    {
        int amountrolled = 0;
        amountrolled = mHuman.roll();
        return( amountrolled );
    }

    int Bunco::humanPlay( const Die & d )          //lets the human player cheat by setting up a constant rolle value on the constant die
    {
        int amountrolled = d.getValue( );
        int amount = mHuman.roll ( amountrolled );
        return( amount );
    }
    
    int Bunco::computerPlay( )              // randomly roll the computer player's die and return what was rolled
    {
        int amountrolled = 0;
        amountrolled = mComputer.roll();
        return( amountrolled );
    }
    
    int Bunco::computerPlay( const Die & d )                //lets the computer cheat by setting up a constant rolle value on the constant die
    {
        int amountrolled = d.getValue( );
        int amount = mComputer.roll ( amountrolled );
        return( amount );
    }

    void Bunco::endTurn()                           //updates the board if the turn has ended and marks the computer or human as winner, if anyone one.
    {
        int humanScore = mHuman.getScore();
        int computerScore = mComputer.getScore();
        if (humanScore > computerScore)                 //if human score is more than computer score, mark human as winner
        {
            mBoard.markHumanAsWinner();
            
        }
        else if (computerScore > humanScore)            //if computer's score is more than human score, mark computer as winner on the board
        {
            mBoard.markComputerAsWinner();
            
        }
    }

    Bunco::ROUNDOUTCOME Bunco::determineRoundOutcome( )            //determine who won the round by checking scores against each other
    {
        int humanScore = mHuman.getScore();
        int computerScore = mComputer.getScore();
        if (humanScore > computerScore)                 //if human score is more than computer score, mark human as winner
        {
            return (ROUNDOUTCOME::HUMANWON);
            
        }
        else if (computerScore > humanScore)            //if computer's score is more than human score, mark computer as winner on the board
        {
            return (ROUNDOUTCOME::COMPUTERWON);}
        else{
                ROUNDOUTCOME result = ROUNDOUTCOME::NOTDECIDED;
            return( result );}
    }

    Bunco::GAMEOUTCOME  Bunco::determineGameOutcome( ) const            //determine who won the game by tallying the round wins against each other
    {
        int humanWins= mBoard.countUpHumanRoundWins();
        int computerWins = mBoard.countUpComputerRoundWins();
        if ((humanWins + computerWins) == 6){
            int humanWins= mBoard.countUpHumanRoundWins();
            int computerWins = mBoard.countUpComputerRoundWins();
            if (humanWins > computerWins){
                return(GAMEOUTCOME::HUMANWONGAME);
            }
            else if (computerWins > humanWins){
                return (GAMEOUTCOME::COMPUTERWONGAME);
            }
            else {
                return (GAMEOUTCOME::TIEDGAME);
                }
        }
        else {
        GAMEOUTCOME result = GAMEOUTCOME::GAMENOTOVER;
        return( result );
        }
    }
    
    bool Bunco::gameIsOver() const                  // checks if the game over?
    {
        GAMEOUTCOME result = determineGameOutcome();
        return( result != GAMENOTOVER );
    }

    Player Bunco::getHuman() const
    {
        return( mHuman );
    }

    Player Bunco::getComputer() const
    {
        return( mComputer );
    }

    Board  Bunco::getBoard() const
    {
        return( mBoard );
    }

}



