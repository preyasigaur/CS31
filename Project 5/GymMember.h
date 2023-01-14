#ifndef GymMember_h
#define GymMember_h

#include <stdio.h>
#include <string>
#include "Kind.h"                   //including the Kind.h header file
#include <iostream>
using namespace std;

class GymMember {
private:            //defining the private accessor operations as given by the class diagram provided namely mKind, mName, mAccountNumber and mWorkoutCount
    Kind mKind;
    string mName;
    string mAccountNumber;
    int mWorkoutCount;
    
public:              //defining the public accessor operations as given by the class diagram provided
    GymMember (string name, string accountnumber, Kind kind);
    int workoutsThisMonth();
    void startNewMonth();
    void newWorkout();
    Kind getKind();
    string getKindAsString();
    string getName();
    string getAccountNumber();
};

#endif 
