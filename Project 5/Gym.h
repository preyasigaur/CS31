#ifndef Gym_h
#define Gym_h

#include <iostream>
#include <string>
#include "Kind.h"               //including the Kind.h header file
#include "GymMember.h"          //including the GymMember.h header file

using namespace std;

class Gym {
private:                            //defining the private accessor operations as given by the class diagram provided
    string mName;
    string mLocation;
    Kind mKind;
    bool hasCardio;
    bool hasWeights;
    bool hasPool;
    bool hasTrack;

public:                             //defining the public accessor operations as given by the class diagram provided
    Gym (string name, string location, Kind kind);
    void setFeatures(bool cardio, bool weights, bool pool, bool track);
    bool canWorkoutHere(GymMember m);
    bool checkin(GymMember &m, bool wantsCardio, bool wantsWeights, bool wantsPool, bool wantsTrack);
    bool hasCardioFeatures();
    bool hasWeightsFeatures();
    bool hasPoolFeatures();
    bool hasTrackFeatures();
    
    Kind getKind();
    string getKindAsString();
    string getLocation();
    string getName();
};

#endif
