// Josh Moots
//Variables and Logic

//compile with Developer Command
//'cl /EHsc main.cpp' is compile
//'main' or 'main.exe'

#include <iostream>
using namespace std;

int main() {
    cout << "lets learn about variables and logic!\n";

    //declaring and defining the variables
    int playerAge = -1;
    string playerName = "Scooby Doo";
    float happinessPercent = 0.61f;
    bool keepPlaying = true;

    //like a branch in UE5
    if(playerAge == -1){
        cout << "how old art thou?\n";
        cin >> playerAge;

        if(playerAge <= 12) {
            cout << "no kids allowed. GET OUT!!\n";
            return 0;
        }
        else {
            cout << "Wow..." << playerAge << " years old? youre old...\n";
        }
    } //end of Age

    if(playerName == "Scooby Doo") {
        cout << "is your name " << playerName << "?\n";
        string input;
        cin >> input;
        if(input == "yes" || input == "Yes" || input == "YES") {
            cout << "want a scooby snack?\n";
        }

    else {
        cout << "ok... what is your name then?\n";
        cin >> playerName;
    }

    cout << "Hello '" << playerName << "'.\n";

    }

    bool debug = false;
    
    if(playerAge == 20 && playerName == "Josh") {
        debug = true;
        cout << "Go kick rocks. Also, debug mode is ON.\n";
    }

    if(debug) {
        cout << "\n \tDEBUG MODE\n\n";
        cout << "playerAge = " << playerAge << ".\n";
        cout << "playerName =" << playerName << ".\n";
        cout << "happinessPercent =" << happinessPercent << ".\n";
        cout << "keepPlaying =" << keepPlaying << ".\n";
    }
    return 0;
}