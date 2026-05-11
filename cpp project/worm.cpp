// Josh Moots Spr26
// worms!
using namespace std;

#include <iostream>
#include <string>           // for getline()
#include <vector>           // for vectors and iterators
#include <ctime> 
#include <cstdlib>
#include <algorithm>

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
    cout << status();
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
        cout <<  damage << " "  << status() << " damage.";
    }

    void eatLemon(){
        cout << "my damage is raised by 1!\n";
        basicWurm.damage ++ 1;
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
    string input; 
    cout << "You have summoned the Grand Wurm.\n";

    // wormys gaining their dirt element and introducing themselves
    basicWurm grandwurm;
    grandwurm.name = "Grand Wurm";
    grandwurm.typing = basicWurm::Type::SOIL;
    grandwurm.speakElement();

    basicWurm rampage;
    rampage.name = "Drakon King";
    rampage.typing = basicWurm::Type::CLAY;
    rampage.speakElement();

    getline(cin, input);
    // Start of Attack

    if(input == "battle"){
        cout << "The Grand Wurm readies its spell\n";
        grandwurm.attack(rampage);

        cout << "The Drakon King unleashes a breath attack!\n";
        rampage.attack(grandwurm);
        }
    

    // Start of Feed
    if (input == "feed") {
        cout << "what would you like to feed your worm?\n";

        if (input == "Lemon"){
            cout << "oouu sour!\n";

            grandwurm.eatLemon();
        }
    }

    // Start of Train
    if (input == "train") {
        cout << "I am so ready :D\n";
    }

    // Start of Stats
    if (input == "stats"){
       grandwurm.speakStats();
    } 

    return 0;
}