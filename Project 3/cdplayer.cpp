#include <iostream>
#include <string>
using namespace std;

bool isValidCDPlayerString(string cdstring);

bool hasCD(string cdstring);

bool isOpen(string cdstring);

int totalTracksPlayed(string cdstring);

int currentTrack(string cdstring);



bool isValidCDPlayerString(string cdstring){
    size_t len = cdstring.size();
    bool player_open = false, disc_in = false, play = false, error = false;    // Defining variables to check whether the player is open, disc is inserted, cd player is playing, etc
    int next = 0, current = -1;
    
    for(int i = 0; i < len; i++)
    {
        char c = cdstring[i];                    // assinging c the value of cdstring[i](the command that is being checked
        if(c =='O'&& player_open == false)
        {
            player_open = true;
        }
        else if(c=='I' && disc_in == false && player_open == true)    // changing disc_in to true if player is open, command is 'I' and no disc is inserted
        {
            disc_in = true;
            current = 0;
        }
        else if(c == 'C' && player_open == true)
        {
            player_open = false;
        }
        else if(c=='P' && player_open == false && disc_in == true)
        {
            play = true;
        }
        else if(c == 'S' && play == true)
        {
            play = false;
        }
        else if(c=='R' && player_open == true && disc_in == true )
        {
            current= -1;
            disc_in = false;
        }
        else if(isdigit(c) && play){                    // If the character/command c is a digit and the cdplayer is playing, then the if statement executes
            next = int(c);
            if(next == current+49){
                current = next-48;
            }
            else
            {
                error = true;                // If the current track and next track are not consecutive, error will be assingned a true value
            }
        }
        else                         // unidentified commands will cause error to be assigned a true value
        {
            error = true;
        }
    }
    if(cdstring[0] != 'O')
    {
        error = true;
    }
    if(error)                     // if error is true, then the function returns false
    {
        return false;
    }
    else
    {
        return true;
    }
}

bool isOpen(string cdstring){
    bool player_open1 = false;       // Pre-assigning player_open1(variable that checks if CDplayer is open) as false(CDplayer is closed
    size_t len = cdstring.size();
    for( int i = 0; i < len ; i++ ){
        char c = cdstring[i];
        if(c == 'O')
        {
            player_open1 = true;
        }
        else if(c == 'C')
        {
            player_open1 = false;
        }
    }
    if(isValidCDPlayerString(cdstring) && player_open1)
        return true;
    else
        return false;
}

bool hasCD(string cdstring){
    bool CD = false;
    size_t len = cdstring.size();
    for(int i = 0; i < len; i++){
           char c = cdstring[i];
        if(c == 'R')
        {
            CD = false;
        }
        else if(c == 'I')
        {
            CD = true;
        }
    }
        if(CD && isValidCDPlayerString(cdstring))
        {
            return true;
        }
        else
        {
            return false;
        }
}


int totalTracksPlayed(string cdstring){
    size_t len = cdstring.size();
    int total = 0;
    for(int i = 0; i < len; i++)
    {
        char c = cdstring[i];
        if(isdigit(c)&& isValidCDPlayerString(cdstring))
            total++;                     // Finding the total number of tracks played
    }
    if(isValidCDPlayerString(cdstring))
    {
        return(total);
    }
    else
    {
        return(-1);
    }
}
int currentTrack(string cdstring){
    size_t len = cdstring.size();
    int current = 1;
    for(int i = 0; i < len ; i++ )
    {
        char c = cdstring[i];
        if(isdigit(c))
            current = int(c)-47;     // Assigning variable current the numerical value if the string contains a numerical value
    }
    if(hasCD(cdstring) == false)
    {
        current = -1;
    }
    if(isValidCDPlayerString(cdstring))
    {
        return(current);
    }
    else
    {
        return(-1);
    }
    
}


int main(){
    string s;
    cout.setf( ios::boolalpha );
    for(;;){
        cout <<"Enter a possible result string: ";
        getline(cin, s); if (s == "quit") break;
        cout << "isValidCDPlayerString returns ";
        cout << isValidCDPlayerString(s) << endl;
        cout << "isOpen(s) returns ";
        cout << isOpen(s) << endl;
        cout << "hasCD(s) returns ";
        cout << hasCD(s) << endl;
        cout << "totalTracksPlayed(s) returns ";
        cout << totalTracksPlayed(s) << endl;
        cout << "currentTrack(s) returns ";
        cout << currentTrack(s) << endl;
        }
    return(0);
}


