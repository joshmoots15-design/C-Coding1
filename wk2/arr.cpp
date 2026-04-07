// Josh Moots Coding 1 SPR26
// Arrays, FOr Loops, Enums, and Switch Statements

//'cl /EHsc arr.cpp' is compile
//'arr' to activate

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    srand(time(0));

    cout << "Its Array time baby!\n";

    // Arrays cannot change size
    // Arrays dont know where the last index is
    // arrays are a list of similar variables
    // arrays are ordered

    int scores [5];     //this is creating an interger array size 5

    scores [0] = 69;
    scores [1] = 4378;
    scores [2] = 3729;
    scores [3] = 382;
    scores [4] = 67;

    cout << "first score is " << scores [0] << ".\n";

    cout << "Here are all of the Scores:\n";

    int index = 0;
    while(index < 5){
        cout << scores[index] << "\n";
        index++;
    }
    
    cout << "Using a For Loop:\n";
    // for loop has iterator bulit in lol
    for(int i = 0; i < 5; i++){
        cout << scores[i] << "\n";
    }

    //we be buliding string arrays for names bay-beee
    string names[10];
    string input;
    index = 0;
    //we want the user to add names to the array
    while(index < 10){
        cout << "type name, or 'done'";
        cin >> input;

        // until they type 'done'
        if(input == "done"){
            cout << "\nDone adding names!.\n";
            break;
        }

         names[index++] = input;
        
    }

    for(int i = 0; i < 10; i++){
        if(names[i] == ""){
            continue;
        }

        cout << names[i] << "\n";
    }
   
    //or the list is full up!
    // show list of names goober


    // create a new string of array
    string newNames[] = {"Apple", "Banana", "Orange",
                         "Pineapple", "Lychee", "Dragonfruit", 
                         "Watermelon", "Coconut", "Cranberry", 
                         "Blueberry"};

    cout << "Here are the new names:\n";
    for(int i = 0; i < 10; i++){
        cout << i + 1 << ". " << newNames [i] << "\n";
    }

    int randIndex = rand() % 10;
    string character = newNames[randIndex];

    cout <<"The " << character << " is the best fruit in the whole wide world!!!\n";

    enum favor {HATE, DISLIKE, LIKE, LOVE};

    switch(rand() % 4){
        case HATE:
            cout << "I HATE " << character << ".\n";
            break;
        case DISLIKE:
            cout << "I dislike " << character << ".\n";
            break;
        case LIKE:
            cout << "I like " << character << ".\n";
            break;
        case LOVE:
            cout << "I think, without any doubt in my mind, " << character << " is the best thing ever.\n";
            break;
    }

    return 0;

}
