// Josh Moots Spr26
// cl /EHsc fx.cpp and fx
// Functions

#include <iostream>
#include <string>           // for getline()
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;


// Declare and Define functions

void sayHello(){
    cout << "Hello!\n";
}

void doAddition(int firstNum, int secondNum) {
    cout << "Our first number is " << firstNum << ".\n";
    cout << "Our second number is " << secondNum << ".\n";
    cout << "Added together is " << firstNum + secondNum << ".\n";
}

int dieRoll(int sides) {
    return rand() % sides + 1;
}

bool askYesNo(string question = "Keep Playing?") {
    while(true) {
         cout << question << "(yes or no).\n";
        string input;
        getline(cin, input);

        if(input == "yes") {
            return true;
        }

        else if(input == "no") {
            return false;
        }

        else {
            cout << "try again. yes or no.\n";
        }
    }
}

void showVec(vector<string>& vec) {
    for(int i = 0; i < vec.size(); i++) {
        cout << vec[i] << endl;
       }
}

void addStringToVec(vector<string>& vec){
    cout << "Add Names?\n";
    string input;
    getline (cin, input);

    vec.push_back(input);

    showVec(vec);
}

int main() {
    srand(time(0));
    vector<string> names = {"The Knight", "Lil' Ghost", "Hornet", "Quirrel", "Grimm"};
    cout << "Funtions!!!!\n";

    showVec(names);

    addStringToVec(names);

    sayHello();
    sayHello();
    

    doAddition(37,63);
    doAddition(37,63);
    
    cout << "imma roll this die! Here we gooooo! And its a(n) " << dieRoll(20) << ".\n";

    doAddition(dieRoll(20), dieRoll(20));

    if(askYesNo()) {
        cout << "starting new thingy.\n";
    }
    else {
        cout << "thanks for doing whatever you are doing lmao.\n";
        return 0;
    }

    return 0;
}