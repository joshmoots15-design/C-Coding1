// Josh Moots Coding 1 SPR26
// Vectors, Iterators, and Algorithms

//'cl /EHsc vec.cpp' is compile
//'vec' to activate

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    cout << "I'm working!!!\n";

    string input;

    do {
        cout << "What do you want?\n";
        cout << "If you want to, you can type 'push'.";

        getline(cin, input);

        if(input == "push") {
            cout << "lets get working on vector of strings gang!\n";

            vector<string> names;

            names.push_back("Hornet");
            names.push_back("Lil Ghost");
            names.push_back("Quirrel");
            names.push_back("The Knight");
            names.push_back("Grimm");

            cout << "here are your names!\n";
            for(int i =0; i < names.size(); i++){
                cout << names[i] << "\n";
            }
        }
        else if(input == "quit") {
            cout << "ok bye, loser jeez.\n";
            break;
        }
        else{
            cout << "try again idiot.\n";
        }
    }
    // creating a new vect

}