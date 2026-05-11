// Josh Moots Spr26
// worms!
using namespace std;

#include <iostream>
#include <string>           // for getline()
#include <vector>           // for vectors and iterators
#include <ctime> 
#include <cstdlib>
#include <algorithm>
#include <fstream>

// vector<string> names = {"grand", "evil", "majestic", "powerful", "sexy"};
// vector<string> elements = {"Soil", "Clay", "Stone", "Dust", "Ore"};

class basicWurm{

public:

    enum Type {
            SOIL,
            CLAY,
            STONE,
            DUST
    };

    string name = "";
    // int name;
    int health;
    int damage; 
    Type typing;
    int energy;
    int power = rand();
    int minPower = -3;
    int maxPower = 3;
    int range = minPower - maxPower;
    int powerRange = (power % range) - maxPower;

// basicWurm(int giveName, int giveType, int giveEnergy){
//         name = giveName;
//         typing = giveType;
//         energy = giveEnergy;
//         status();
//     }

basicWurm() {
        cout << "hewwo! I'm a worm!.\n";
        name = "grandwurm";
        health = 7;
        damage = 3;
        typing = SOIL;
        energy = 10;
        // element = elements[rand() % elements.size()] + " element";
        cout << status();
    }

basicWurm (string giveName, Type giveType, int giveEnergy) {
    name = giveName;
    typing = giveType;
    energy = giveEnergy;
    health = 0;
    damage = 0;
    status();
}

    string status(){
    if(typing == SOIL){
        return "Soil"; 
    }
    else if(typing == CLAY){
        return "Clay";
    }
    else if(typing == STONE){
        return "Stone";
    }
    else if(typing == DUST){
        return "Dust";
    }
    else{
        return "No Typing";
    }
    }

    void speakElement() {
        cout << "haii i am " << name << " and i am the " << status() << " element <3\n";
    }

    void speakStats(){
        cout << "I am " << name << " and i have " << health << " health remaining, and I do ";
        cout <<  damage << " "  << status() << " damage.\n";
    }

    void eatLemon(){
        cout << "my damage is raised by x1.5!\n";
        basicWurm::damage += damage * 1.5;
    }

    void eatCherry(){
        cout << "my health is raised by x1.5!\n";
        basicWurm::health += health * 1.5;
    }

    void doSquiggle(){
        cout << "I am squiggling!\n";
        basicWurm::damage += damage + powerRange;
        cout << "I squiggled " << powerRange << " amount!\n";

    }

    void doSquirm(){
        cout << "I am squirming!\n";
        basicWurm::health += health + powerRange;
        cout << "I squiggled " << powerRange << " amount!\n";

    }

    void read(string path = "worms.txt"){
     string line;
    ifstream readFile("worms.txt");
    if(readFile.is_open()){
        cout << "The file is open.\n";
        while(getline(readFile, line)) {
            cout << line << endl;
        }
    }
    else{
        cout << "Couldnt open the file";
    }

    readFile.close();
}

    void attack(basicWurm& opponent){
        if(typing == SOIL && opponent.typing == CLAY){
        // double damage
        opponent.health -= damage * 2;
    }
    else if (typing == CLAY && opponent.typing == DUST){
        // double damage
        opponent.health -= damage * 2;
    }

    else if (typing == DUST && opponent.typing == STONE){
        // double damage
        opponent.health -= damage * 2;
    }

    else if (typing == STONE && opponent.typing == SOIL){
        // double damage
        opponent.health -= damage * 2;
    }

    else{
        opponent.health -= damage;
    }

    cout << "i am doing " << damage << " multipied!\n";    
    cout << opponent.name << " now has " << opponent.health << " health remaining!\n";

        // if(opponent.health <= 0) return true;
        // else                     return false;
    }
    };

int main(){
    srand(time(0));

    // wormys gaining their dirt element and introducing themselves
    basicWurm grandwurm;
    grandwurm.name = "Grand Wurm";
    grandwurm.typing = basicWurm::Type::SOIL;
    grandwurm.speakElement();

    basicWurm rampage;
    rampage.name = "Drakon King";
    rampage.typing = basicWurm::Type::CLAY;
    rampage.health = 500;
    rampage.speakElement();

    do {
    string input; 
    cout << "What would you like to do?.\n";
    cout << "Train\n";
    cout << "Feed\n";
    cout << "Battle\n";
    cout << "Stats\n";
    cout << "Quit\n";

    getline(cin, input);
    // Start of Attack

    if(input == "battle"){
        cout << "The Grand Wurm readies its spell\n";
        grandwurm.attack(rampage);

        cout << "The Drakon King unleashes a breath attack!\n";
        rampage.attack(grandwurm);
        }

    // Start of Feed
    else if(input == "feed") {
        cout << "what would you like to feed your worm?\n";
        cout << "Lemon\n";
        cout << "Cherry\n";

        cin >> input;

        if (input == "lemon"){
            cout << "oouu sour!\n";
            grandwurm.eatLemon();
        }

        else if (input == "cherry"){
            cout << "oouu tart!\n";
            grandwurm.eatCherry();
        }

        else {
            break;

            return 0;
        }
        
    }

    // Start of Train
    else if (input == "train") {
        cout << "What workout would you like to do?\n";
        cout << "Squiggle\n";
        cout << "Squirm\n";

        cin >> input;

        if (input == "squiggle"){
            grandwurm.doSquiggle();
        }


        else if (input == "squirm"){
            grandwurm.doSquirm();
        }
    }

    // Start of Stats
    else if (input == "stats"){
       grandwurm.speakStats();
    } 

    // Start of Quit
    else if (input == "quit"){
        cout << "thanks for playin!";
       break;
    }

    else if (input == "name"){
        cout << "lets pick a new name!";

        read();
    }

    else {
        cout << "sorry I do not recoginze that?\n";
    }


    } while(true);

         return 0;
    } 

   