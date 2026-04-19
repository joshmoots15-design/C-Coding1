// Josh Moots Spr26 Coding 1 cpp Project.
// for windows, it's 'cl /EHsc pro.cpp and type pro'

// create a .cpp program that will allow the user to 
// add, edit, remove, and show all games (sorted), and then quit
// use vectors, iters, and algors to do so
// pseidocode to organize your thoughts
// show available comms to the user at the top of each loop
//  the games do not to save between launches of the program
// the user should type the command they want to use as a word
        // First I should put out the available commands
            //"add", "remove", "random", "sort", "rate", "quit" 
        // then ask for the player to list games
        // display commands again
        // "add" adds games to the list
        // "remove" gets rid a game from the list
        // "rate" randomly picks a game from the list and 
        // then will ask you to rate it out of ten.
        // "quit" leaves the game


#include <iostream>
#include <string>           // for getline()
#include <vector>           // for vectors and iterators
#include <algorithm>        // for find(), sort(), random_shuffle()

using namespace std;

int main() {
        cout << "Im ready to do stuff and things!\n";

        int numberRate = -1;
    // Start of the 'game'
    do{
        cout << "Here are your options:\n";
        cout << "'add', 'remove', 'rate', or 'quit'.\n";

        string input;

        int index = 0;

        getline (cin, input);

    //  Start of 'add'
        if(input == "add") {
            cout << "You may now start adding games! Type 'done' when finished!\n";

            string names[10];
            string input;
            index = 0;

            while(index < 10){
                cout << "go ahead and start addin' bay-beeee!\n";
                cin >> input;

                for(int i = 0; i < 10; i++){        
                        if(names[i] == ""){
                            continue;
                        }

                        cout << names[i] << "\n";
                    }

                if(input == "done"){
                    cout << "you have finished adding names!\n";
                break;
                } 

                names[index++] = input;
                }
            }
        //end of add

    // start of rate
         else if(input == "rate") {
            cout << "Pick one to rate out of ten:.\n";

            // using a collection initializer to add favs at creation of vector.
            vector<string> favs = {"Hotline Miami", "Hollow Knight", "Silksong", "Nine Sol", "Overwatch", "Marvel Rivals", "Mario Party"};

            // building an iterator. it points to a 'spot' in a vector.
            vector<string>::iterator iter;

            cout << "here are your favs!\n";
            for(int i = 0; i < favs.size(); i++) {
                cout << "    " << favs[i] << "\n";
            }

            // make iter point at the first element in the vector
            iter = favs.begin(); 

            cout << "What game would you like to rate?\n";

            getline(cin, input);
            // use the find algorithm
            iter = find(favs.begin(), favs.end(), input);
            
            if(iter != favs.end()) {
                cout << "We've found " << *iter << "! Now please rate the game.\n";

                if (numberRate == -1) {
                    cin >> numberRate;

                    if(numberRate <= 10){
                        cout << "You rated this game " << numberRate << " out of 10.\n";
                    }

                    else{
                            "Please pick a number out of ten.\n";

                            return 0;
                    }
                    getline(cin, input);

                    *iter = input;      // changing the fav.
                }
            }
            else {
                cout << "We couldn't find that name.\n";
            }
        } 


    // start of quit
         else if(input == "quit") {
            cout << "Thanks for playing.\n";
            break;
        }

        else{
                cout << "I do not understand. Try Again.\n";
        }
    } while(true);

    return 0;
}

