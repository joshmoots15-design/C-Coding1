// Josh Moots Spr26
// worms!

#include <iostream>
#include <string>           // for getline()
#include <vector>           // for vectors and iterators
#include <ctime> 
#include <cstdlib>
#include <algorithm>

using namespace std;

vector<string> names = {"grand", "evil", "majestic", "powerful", "sexy"};
vector<string> elements = {"Soil", "Clay", "Stone", "Dust", "Ore"};

class basicWurm{
public:
    string name;
    string element;
    int health;
    int damage; 

    basicWurm() {
        cout << "hewwo! I'm a worm!.\n";
        name = names[rand() % names.size()] + "worm";;
        health = 7;
        damage = 3;
        element = elements[rand() % elements.size()] + " element";
    }

    void speakElement() {
        cout << "haii i am " << name << " and i am the " << element << " <3\n";
    }

    bool attack(basicWurm& opponent){
        if(element == "Soil" && opponent.element == "Clay"){
        // double damage
        opponent.health -= damage * 2;
    }
    else if (element == "Clay" && opponent.element == "Dust"){
        // double damage
        opponent.health -= damage * 2;
    }

    else if (element == "Dust" && opponent.element == "Stone"){
        // double damage
        opponent.health -= damage * 2;
    }

    else if (element == "Stone" && opponent.element == "Ore"){
        // double damage
        opponent.health -= damage * 2;
    }

    else if (element == "Ore" && opponent.element == "Soil"){
        // double damage
        opponent.health -= damage * 2;
    }

    else{
        opponent.health -= damage;
    }

    cout << "i am doing " << damage << " multipied!\n";    
    cout << opponent.name << " now has " << opponent.health << " health remaining!\n";

        if(opponent.health <= 0) return true;
        else                     return false;
    }

};

class evilWyrm : public basicWurm{
    public:
    
    evilWyrm(){
        name = "boss";
    }
    
};

int main(){
    srand(time(0));
    string input; 
    cout << "You have summoned the Grand Wurm.\n";

    // wormys gaining their dirt element and introducing themselves
    basicWurm grandwurm;
    grandwurm.name = "Grand Wurm";
    // grandwurm.speakElement("Soil"); 
    grandwurm.speakElement();

    evilWyrm rampage;
    rampage.name = "Drakon King";
    // rampage.speakElement("Clay");
    rampage.speakElement();

    // Start of Attack
    cout << "The Grand Wurm readies its spell\n";
    grandwurm.attack(rampage);

    cout << "The Drakon King unleashes a breath attack!\n";
    rampage.attack(grandwurm);

    getline(cin, input);

    // Start of Defend
    // Start of Train
    // Start of Feed

    if (input == "feed") {
        cout << "yummy :D\n";
    }

    if (input == "train") {
        cout << "I am so ready :D\n";
    }

    // Start of Elemental Swap 

    return 0;
}