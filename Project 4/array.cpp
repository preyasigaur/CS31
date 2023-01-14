#include <iostream>
#include <string>
using namespace std;

// Project 4 function implementations go here...

int locateMinimum( const  string  array[ ],  int  n );
int countCommonElements( const string array1[ ], int  n1, const string array2[ ], int n2 );
int countVowels( const string array[ ], int n );
bool hasThreeOfX( const string array[ ], int n, string x );
string majorityElement( const string array[ ], int  n );
bool shiftRight( string array[ ], int n, int amount, string placeholder );
bool rotateLeft( string array[ ], int n, int amount );
int replaceAll( string array[ ], int n, char letterToReplace, char letterToFill );

int locateMinimum( const  string  array[ ],  int  n ){
if (n > 0) {
        int position = 0;
        string s = array [0];
        for (int j=0; j < n; j++){
            if (s > array[j]){
                s = array[j];
                position = j;
            }}
    return (position);
}
else {
        return (-1);
    }
}

int countVowels ( const string array[ ], int n ){
        int count = 0;
        if (n > 0) {
            for (int i = 0; i < n; i++){
            string s = array [i];
                size_t len = s.length();
                for (size_t position = 0; position < len; position++){
                char c = s.at(position);
                    if ( c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'y' ||c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U' || c == 'Y' ) {
                    count++;}
            }
        }
            return (count);
        }
        else {
            return (-1);
        }
}

string majorityElement( const string array[ ], int  n ){
if (n > 0) {
    for (int i = 0; i < n; i++){
            int count = 0;
            string s = array [i];
                for (int j=0; j < n; j++){
                if (s == array[j]){
                    count++;}}
                if ((count > n/2)){
                    return (s);
                }
            }
    return ("");}
else {
    return ("");
}}

int replaceAll( string array[ ], int n, char letterToReplace, char letterToFill ){
    int count = 0;
    if (n > 0) {
        for (int i = 0; i < n; i++){
        string s = array [i];
            size_t len = s.length();
            for (size_t position = 0; position < len; position++){
            char c = s.at(position);
                if ( c == letterToReplace) {
                s[position] = letterToFill;
                count++;}
        }
    }
        return (count);
    }
    else {
        return (-1);
    }
}

bool hasThreeOfX( const string array[ ], int n, string x ){
    if (n > 0) {
       int count = 0;
        for (int j=0; j < n; j++){
            if (x == array[j])
                count++;
        }
        if (count == 3){
        return (true);
    }
    else
        return (false);
    }
else
        return (false);
}

int countCommonElements( const string array1[ ], int n1,
                         const string array2[ ], int n2 )
{
    if (n1 > 0 && n2> 0) {
       int count = 0;
        for (int i=0; i < n1; i++){
            string s = array1[i];
            for (int j=0; j < n2; j++){
            if (s == array2[j])
                count++;
        }
        }
        return (count);
    }
else{
        return (-1);
    }
}

bool rotateLeft(string array[], int n, int amount)
{
    if(n>0 && amount >0 && amount%n!=0){
        for(int j = 0;j<amount;j++){
            string placehold = array[0];
            for(int i = 0; i<n-1 ;i++){
                array[i]= array[i+1];
            }
                array[n-1]= placehold;
        }
        return(true);
    }
    else{
        return(false);
    }
}

bool shiftRight( string array[ ], int n, int amount, string placeholder ){
    if(n>0 && amount >0){
        for(int j = 0;j<amount;j++){
            for(int i = n-1;i>0;i--){
                array[i]= array[i-1];
            }
                array[0]= placeholder;
        }
        return(true);
    }
    else{
        return(false);
    }
}

int main()
{
    int n = 8;
    int n1 = 8;
    int n2 = 5;
    int amount = 3;
    string placeholder = "foo";
    string x = "mama";
    string array[8]= {  "samwell", "jon", "margaery", "daenerys", "tyrion", "sansa", "magdalena", "jon" };
    string array1[8] = {  "samwell", "jon", "margaery", "daenerys", "tyrion", "sansa", "magdalena", "jon" };
    string array2[5] = { "mama", "mama", "12", "sansa", "mama" };
    char letterToReplace = 'a';
    char letterToFill = 'Z';

    cout << "The output of the functions are as follows: "<< endl<< endl;
    cout  << "replaceAll returns "<< replaceAll(array, n,letterToReplace, letterToFill) << endl;
    cout  << "locateminimum returns "<< locateMinimum(array, n) << endl;
    cout  << "countCommonElements returns "<< countCommonElements(array1, n1,array2,n2) << endl;
    cout  << "countVowels returns "<< countVowels(array2, n2) << endl;
    cout  << "hasThreeOfX returns "<< hasThreeOfX(array2, n2, x) << endl;
    cout  << "majorityElement returns "<< majorityElement(array2, n2) << endl;
    cout  << "shiftRight returns "<< shiftRight(array, n,amount,placeholder) << endl;
    cout  << "rotateLeft returns "<< rotateLeft(array, n,amount) << endl;

    return 0;
}
