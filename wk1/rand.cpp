// Josh Moots Coding 1 Spring
// Random Numbers, Switch Statements and While Loops

#include <iostream>
#include <cstdlib>                      // for srand and rand
#include <ctime>                        //for time

using namespace std;

int main() {
    //only once, at the beginning of program
    //seed the random # generator
    srand (time(0));

    cout << "random numbers!!\n";

    cout << "here is our first random number: " << rand() << ".\n";
    
    int counter = 0;
    while (counter++ <10){
        int number = rand ();
        int min = 50;
        int max = 100;
        int range = max - min;
        int clampedNumber = (number % range) + min;

        cout << clampedNumber << endl;

        //cout << (rand() % 100) + 1 << endl;
    }

    
    // set variables
        // the rand #
        int number = (rand() % 100) + 1;

        // the guess/input
        int guess = -1;
        int totalGuesses = 0;
    // start loop
    while(true) {

    
    // ask player input between 1 and 10
    cout << "im thinkin of a number between 1 and 100, try and guess it!\n>>";
    // get the player input
        cin >> guess;
        totalGuesses++;
    // evaluate the players guess
        // too high
        if(guess > number){
            cout << "too high bozo!\n";
        }

        // too low
        if(guess < number){
            cout << "too low bozo!\n";
        }

        // correct
        if(guess == number){
            cout << "You got it right!\n";
            cout << "you got it in " << totalGuesses << " guesses!\n";
            //break out of loop
            break;
        }
            
    }
    // if incorrect keep guessing   


    return 0;
}

