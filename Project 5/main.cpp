#include <iostream>
#include <string>
#include <cassert>
#include "Kind.h"
#include "Gym.h"
#include "GymMember.h"

using namespace std;

int main()
{
Gym gym( "Wooden Centre", "Bruin Plaza", REGULAR);
gym.setFeatures(false, true, false, true );
GymMember me( "Patelian", "6692515164", PREMIER );
assert( me.workoutsThisMonth() == 0 );
me.startNewMonth();
me.newWorkout();
assert( me.workoutsThisMonth() == 1 );
    
if (gym.canWorkoutHere( me ))
gym.checkin( me, true, false, true, false );
assert( me.workoutsThisMonth() == 1 );

cout << "This program is some amazing stuff!!" << endl;
    
return (0);
}


