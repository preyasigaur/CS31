#include "Kind.h"                          //incuding the Kind.h header file
#include "GymMember.h"                     //including the GymMember.h header file 
#include <iostream>
#include <string>

using namespace std;

GymMember::GymMember (string name, string accountnumber, Kind kind){
    mKind = kind;
    mName = name;
    mAccountNumber = accountnumber;
    mWorkoutCount = 0;                  //initializing mWorkoutCount to 0
}

void GymMember::newWorkout(){
    mWorkoutCount++;}

void GymMember::startNewMonth(){
    mWorkoutCount = 0;}                 //resetting the workout count for every new month

int GymMember::workoutsThisMonth(){
    return (mWorkoutCount);}            //calling to return the current workout count of a member

Kind GymMember::getKind(){
    return (mKind);}

string GymMember::getKindAsString(){                //returning the enum values as a string
    switch (mKind){
        case REGULAR:
            return ("REGULAR");
            break;
        case PREMIER:
            return ("PREMIER");
            break;
        case EXECUTIVE:
            return ("EXECUTIVE");
        default:
            return ("OTHER");
}}

string GymMember::getName(){
    return (mName);}

string GymMember::getAccountNumber(){
    return(mAccountNumber);}
