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

void showVec(vector<string>& vec) {
    for(int i = 0; i < vec.size(); i++) {
        cout << vec[i] << endl;
       }
}

void addStringToVec(vector<string>& vec){
    cout << "You may now start adding games! Type 'done' when finished!\n";
    string input;
    getline (cin, input);

    vec.push_back(input);

    showVec(vec);
}

int main() {
        cout << "Im ready to do stuff and things!\n";

        vector<string> listGames = {"Hotline Miami", "Hollow Knight", "Silksong", 
            "Nine Sol", "Overwatch", "Sol Cesto", "Peak"};

            int i = 0;

        int numberRate = -1;
    // Start of the 'game'
    do{
        cout << "Here are your options:\n";
        cout << "'add', 'display', 'remove', 'rate', or 'quit'.\n";

        string input;

        int index = 0;

        getline (cin, input);

    //  Start of 'add'
        if(input == "add") {
            cout << "Here is the current list of games!\n";

            showVec(listGames);

            string names[5];
            string input;
            index = 0;

            while(index < 5){
                cout << "go ahead and start addin' bay-beeee!\n";
                cin >> input;

                for(int i = 0; i < 5; i++){  
            
                        if(names[i] == ""){
                            continue;
                        }
                        cout << names[i] << ".\n";
            
                        addStringToVec(listGames);
                        
                            break;
                }

            if (input == "done") {
                cout << "You have finished adding names!\n";
                break;
            }  
                names[index++] = input; 
                }
            }
        //end of add

        // start of display
        else if(input == "display"){
            showVec(listGames);
        }

    // start of rate
         else if(input == "rate") {
            cout << "Pick one to rate out of ten:.\n";

            sort(listGames.begin(), listGames.end());

            vector<string>::iterator iter;

            cout << "here is the game list!\n";
            for(int i = 0; i < listGames.size(); i++) {
                cout << "    " << listGames[i] << "\n";
            }

            iter = listGames.begin(); 

            cout << "What game would you like to rate?\n";

            getline(cin, input);

            iter = find(listGames.begin(), listGames.end(), input);
            
            if(iter != listGames.end()) {
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

        else if(input == "edit") {
            
            showVec(listGames);

            vector<string>::iterator iter;

            cout << "Here is the list of games!\n";
            for(int i = 0; i < listGames.size(); i++) {
                cout << "    " << listGames[i] << "\n";
            }

            iter = listGames.begin(); 

            cout << "Let's look at this one: " << *iter << ".\n";

            iter += 1;

            cout << "Lets also look at this one: " << *iter << ".\n";

            cout << "Which game would you like to select?\n";

            getline(cin, input);
            // use the find algorithm
            iter = find(listGames.begin(), listGames.end(), input);
            
            if(iter != listGames.end()) {
                cout << "We've found " << *iter << "!\n";
                cout << "Would you like to change this game?\n";
                getline(cin, input);

                if (input == "yes") {
                    cout << "What would you like to change this game to instead?\n";
                    getline(cin, input);

                    *iter = input;      
                }

                cout << "here is the updated list\n";
                for(int i = 0; i < listGames.size(); i++) {
                    cout << "    " << listGames[i] << "\n";
                }
            }
            else {
                cout << "We couldn't find that name.\n";
            }

        }

    // start of remove
        else if(input == "remove"){
            sort(listGames.begin(), listGames.end());

            cout << "Choose one to remove!\n";

            for(int i = 0; i < listGames.size(); i++){
                cout << listGames[i] << endl;
            }

            cout << "What game would you like to remove from the list?\n";
            getline(cin, input);

            auto iter = find(listGames.begin(), listGames.end(), input);

            if(iter != listGames.end()) {
                cout << "We have found the name, we getting rid of it!\n";
                listGames.erase(iter);
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