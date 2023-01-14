//
//  Player.cpp
//  Bunco
//
//  Created by Howard Stahl on 1/27/17.
//  Copyright © 2017 Howard Stahl. All rights reserved.
//

#include "Player.h"



namespace cs31
{
    
    Player::Player() : mDie( 6 ), mScore( 0 ), mRound( 0 )
    {
        
    }
   
    int Player::roll( )
    {
        mDie.roll();        // rolling the a random value of die
        int valueOfDie = mDie.getValue();
        if (valueOfDie == mRound) {
            mScore++;
        }
        return( valueOfDie );
    }

    int Player::roll( int amount )
    {
        mDie.setValue(amount);          //setting the value of the die
        int val = mDie.getValue();
        if (val == mRound) {
            mScore++;
        }
        return( val );
    }
    
    void Player::setRound( int round )
    {
            mRound = round;
            mScore = 0;         //resetting the value of score with every new round set 
    }
    
    int  Player::getScore( ) const
    {
        return( mScore );
    }

    int Player::getRound() const
    {
    return (mRound);
    }
    
}
