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
        // "random" mixes up the list
        // "sort" orders the list alphbetically
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

    do{
        cout << "Here are your options:\n";
        cout << "'add', 'remove', 'random', 'sort', 'rate', or 'quit'.\n";

        string input;

        getline (cin, input);

        if(input == "add") {
            cout << "You may now start adding games! Type 'done' when finished!\n";
        }

    } while (true);







    return 0;
}

