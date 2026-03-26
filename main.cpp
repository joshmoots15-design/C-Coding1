// Josh Moots Coding 1 Spring 26
// My First C++ Program

#include <Iostream>
#include <string>            //for playerName

using namespace std;

//program start
int main() {
    // variables declared at the top is the best
    string playerName;         //use camelCase

    cout << "What is your name, traveller?";

    //assign whatever the player types as the value of playerName
    cin >> playerName;

    cout <<"Hello " << playerName << "." << endl;

    //cout << "Hello World!" << endl;

    return 0;                 //Program End
}