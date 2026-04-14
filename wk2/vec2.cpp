// Josh Moots Coding 1 Spr26
// Vectors, Iterators, and Algorithms

// for windows, it's 'cl /EHsc vec.cpp && vec'
// for macOS, it's 'g++ vec.cpp -o vec && ./vec'

// create a .cpp program that will allow the user to 
// add, edit, remove, and show all games (sorted), and then quit
// use vectors, iters, and algors to do so
// pseidocode to organize your thoughts
// show available comms to the user at the top of each loop
//  the games do not to save between launches of the program
// the user should type the command they want to use as a word

#include <iostream>
#include <string>           // for getline()
#include <vector>           // for vectors and iterators
#include <algorithm>        // for find(), sort(), random_shuffle()

using namespace std;

int main() {
    cout << "Let's learn about vectors!\n";

    vector<string> favGames = {"Hollow Knight", "Silksong", "Sol Cesto"};
    string input;
    // int numberInput = stoi(input);


    do {
        cout << "What would you like to do?\n";
        cout << "You can type 'quit', 'push', 'find', 'remove'.\n";

        getline(cin, input);        // get input from the player

        if(input == "push") {
            cout << "\nLet's make our first vector of strings.\n";

            vector<string> names;

            // add some names with names.push_back()
            names.push_back("Edric Muller");
            names.push_back("Ishmael Rozario");
            names.push_back("Faylinn Graeves");
            names.push_back("Martyr Long");
            names.push_back("Henry Quetzal");

            cout << "here are your names!\n";
            for(int i = 0; i < names.size(); i++) {
                cout << "    " << names[i] << "\n";
            }

            cout << "There are " << names.size() << " names.\n\n";

            cout << *(names.end() - 1) << " is sour. Let's get rid of him.\n";
            
            names.pop_back();       // pop_back() removes the last element from the vector
            
            cout << "here are your names!\n";
            for(int i = 0; i < names.size(); i++) {
                cout << "    " << names[i] << "\n";
            }


        } // end of 'push'
        else if(input == "find") {
            cout << "Let's try to use the find algorithm.\n";

            // using a collection initializer to add favs at creation of vector.
            vector<string> favs = {"Bells of Bloodwryte", "No Strings Attached", "Sink or Swim"};

            // building an iterator. it points to a 'spot' in a vector.
            vector<string>::iterator iter;

            cout << "here are your favs!\n";
            for(int i = 0; i < favs.size(); i++) {
                cout << "    " << favs[i] << "\n";
            }

            // make iter point at the first element in the vector
            iter = favs.begin(); 

            // the asterisk is a "dereference operator"... so that we can get 
                // the value that the iter is pointing at.
            cout << "iter is pointing at " << *iter << ".\n";

            iter += 1;

            cout << "Now iter is pointing at " << *iter << ".\n";

            cout << "What name would you like to select?\n";

            getline(cin, input);
            // use the find algorithm
            iter = find(favs.begin(), favs.end(), input);
            
            if(iter != favs.end()) {
                cout << "We've found " << *iter << "!\n";
                cout << "Would you like to change this fav?\n";
                getline(cin, input);

                if (input == "yes") {
                    cout << "What would you like to change this fav to?\n";
                    getline(cin, input);

                    *iter = input;      // changing the fav.
                }

                cout << "here are your updated favs!\n";
                for(int i = 0; i < favs.size(); i++) {
                    cout << "    " << favs[i] << "\n";
                }
            }
            else {
                cout << "We couldn't find that name.\n";
            }

        }
        else if(input == "quit") {
            cout << "Thanks for playing.\n";
            break;
        }

        else if (input == "remove") {

            sort(favGames.begin(), favGames.end());

            cout << "Here are your favorite games:\n";

            for(int i = 0; i < favGames.size(); i++){
                cout << favGames[i] << endl;
            }

            cout << "What game would you like to remove from the list?\n";
            getline(cin, input);

            auto iter = find(favGames.begin(), favGames.end(), input);

            if(iter != favGames.end()) {
                cout << "We have found the name, we getting rid of it!\n";
                favGames.erase(iter);
            }

    
        }
        else {
            cout << "I didn't recognise that command.\n";
        }

    } while(true);

    // create a new vector of strings

    return 0;
}