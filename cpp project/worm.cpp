// Josh Moots Spr26
// worms!

#include <iostream>
#include <string>           // for getline()
#include <vector>           // for vectors and iterators
#include <ctime> 
#include <cstdlib>
#include <algorithm>

using namespace std;

// vector<string> names = {"grand", "evil", "majestic", "powerful", "sexy"};
vector<string> elements = {"Soil", "Clay", "Stone", "Dust", "Ore"};

class basicWurm{
// private:
    // string name;
    // string element;
    // int health;
    // int damage; 
    // int typing;
    int energy;

public:
    // string name;
    string element;
    int name;
    int health;
    int damage; 
    int typing;
    // int energy;

basicWurm(int giveName, int giveType, int giveEnergy){
        name = giveName;
        typing = giveType;
        energy = giveEnergy;
        status();
    }

basicWurm() {
        cout << "hewwo! I'm a worm!.\n";
        name = 5;
        health = 7;
        damage = 3;
        typing = 10;
        energy = 10;
        // element = elements[rand() % elements.size()] + " element";
        status();
    }

    // basicWurm(){
    //     name = "basicWurm";
    //     typing = 10;
    //     energy = 10;
    // }
    
    // while(energy > 0){
    void status(){
        if(typing < 5){
        cout << "Soil!\n"; 
    }
    else if(typing < 10){
        cout << "Clay.\n";
    }
    else if(typing < 15){
        cout << "Stone.\n";
    }
    else{
        cout << "Dust.\n";
    }
    }
    
    };
        // if(typing < 5) cout << "Soil!\n";
        // else if(typing < 10) cout << "Clay.\n";
        // else if(typing < 15) cout << "Stone.\n";
        // else cout << "Dust!\n";

    void speakElement() {
        cout << "haii i am " << name << " and i am the " << typing << "element <3\n";
    }

    //  void speakElement() {
    //     cout << "haii i am " << name << " and i am the " << element << " <3\n";
    // }

     bool attack(basicWurm& opponent){
        if(typing == "Soil" && opponent.typing == "Clay"){
        // double damage
        opponent.health -= damage * 2;
    }
    else if (typing == "Clay" && opponent.typing == "Dust"){
        // double damage
        opponent.health -= damage * 2;
    }

    else if (typing == "Dust" && opponent.typing == "Stone"){
        // double damage
        opponent.health -= damage * 2;
    }

    else if (typing == "Stone" && opponent.typing == "Ore"){
        // double damage
        opponent.health -= damage * 2;
    }

    else if (typing == "Ore" && opponent.typing == "Soil"){
        // double damage
        opponent.health -= damage * 2;
    }

    else{
        opponent.health -= damage;
    }

    // bool attack(basicWurm& opponent){
    //     if(element == "Soil" && opponent.element == "Clay"){
    //     // double damage
    //     opponent.health -= damage * 2;
    // }
    // else if (element == "Clay" && opponent.element == "Dust"){
    //     // double damage
    //     opponent.health -= damage * 2;
    // }

    // else if (element == "Dust" && opponent.element == "Stone"){
    //     // double damage
    //     opponent.health -= damage * 2;
    // }

    // else if (element == "Stone" && opponent.element == "Ore"){
    //     // double damage
    //     opponent.health -= damage * 2;
    // }

    // else if (element == "Ore" && opponent.element == "Soil"){
    //     // double damage
    //     opponent.health -= damage * 2;
    // }

    // else{
    //     opponent.health -= damage;
    // }

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