#include <iostream>
#include "Kind.h"                       //including the Kind.h header file
#include "GymMember.h"                  //including the GymMember.h header file
#include "Gym.h"                        //including the Gym.h header file
#include <string>

using namespace std;

Gym::Gym (string name, string location, Kind kind){
    mKind = kind;
    mName = name;
    mLocation = location;
    hasCardio = false;                          //initializing the bool value of hasCardio to false
    hasWeights = false;                         //initializing the bool value of hasWeights to false
    hasPool = false;                            //initializing the bool value of hasPool to false
    hasTrack = false;                           //initializing the bool value of hasTrack to false
}

void Gym::setFeatures(bool cardio, bool weights, bool pool, bool track){            //sets the input values for the features in the gym i.e. track, pool, weights, cardio
    hasWeights = weights;
    hasCardio = cardio;
    hasPool = pool;
    hasTrack = track;
}

bool Gym::canWorkoutHere(GymMember m){                      //checks if the gym member can workout at the particular gym
    string gymtype = getKindAsString();                     //reads the type of gym as a string as we can easily compare two strings but not two enum values
    string membership = m.getKindAsString();                //reads the type of membership as a string as we can easily compare two string but not two enum values
    if (gymtype == membership){                             // if the type of membership and the type of gym matches then the member can workout there
        return true;}
    else if (gymtype == "REGULAR" && membership == "PREMIER"){          //a premier member can work out at a regular gym as well as a premier gym
        return true;}
    else if (gymtype == "REGULAR" && membership == "EXECUTIVE"){        //an executive member can work out at a regular gym as a well as a premier and executive gym
        return true;}
    else if (gymtype == "PREMIER" && membership == "EXECUTIVE"){
        return true;}
    else{return false;}
}

bool Gym::checkin(GymMember &m, bool wantsCardio, bool wantsWeights, bool wantsPool, bool wantsTrack){          //checks if the member wants to workout at the gym by checking the features of gym match the feature requirements of the gym member
if (canWorkoutHere(m) == true){                             //this if-statement tells that the member can check in at the gym if they can workout there according to their member ship and the gym type
    if(hasCardio == wantsCardio || hasCardio == true){
        if(hasPool == wantsPool || hasPool == true){
            if(hasWeights == wantsWeights || hasWeights == true){
                if (hasTrack == wantsTrack || hasTrack == true){
                    m.newWorkout();             //when the member checks in at a gym, the mWorkoutCount increments by 1
                    return true;}
                    else {return false;}
                }
                else {return false;}
            }
            else {return false;}
        }
        else {return false;}
    }
else {return false;}
}

bool Gym::hasCardioFeatures(){
    return(hasCardio);}

bool Gym::hasWeightsFeatures(){
    return(hasWeights);}

bool Gym::hasPoolFeatures(){
    return(hasPool);}

bool Gym::hasTrackFeatures(){
    return(hasTrack);}

Kind Gym::getKind(){
    return (mKind);}

string Gym::getLocation(){
    return (mLocation);}

string Gym::getName(){
    return (mName);}

string Gym::getKindAsString(){
    switch (mKind){
        case REGULAR:
            return ("REGULAR");
            break;
        case PREMIER:
            return ("PREMIER");
            break;
        case EXECUTIVE:
            return ("EXECUTIVE");
            break;
        default:
            return ("OTHER");
}}


