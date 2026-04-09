// Josh Moots Coding 1 SPR26
// Vectors, Iterators, and Algorithms

//'cl /EHsc vec.cpp' is compile
//'vec' to activate

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    cout << "I'm working!!!\n";

    string input;

   do{
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
            else if(input == "find"){
                cout << "lets try to use the find algorithm.\n";

                vector<string> favs = {"Hollow Knight", "Silksong", "Nine Sols"};

                vector<string>::iterator iter;

                cout << "here are your favs!\n";
                for(int i = 0; i < favs.size(); i++) {
                    cout << "   " << favs[i] << "\n";
                }

                iter = favs.begin();

                cout << "iter is pointing at " << *iter << ".\n";

                iter += 1;

                cout << "Now iter is pointing at " << *iter << ".\n";

                cout << "what name would you like to select?\n";

                getline(cin, input);

                find(favs.begin(), favs.end(), "Silksong");

                if(iter != favs.end()) {
                    cout << "We've found " << *iter << "!\n";
                    cout << "Would you like to change this fav?\n";
                    getline(cin, input);

                    *iter = input
                }

                
                else {
                    cout << "We couldnt find that name.\n";
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
}