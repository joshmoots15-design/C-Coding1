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
    int minPower = 1;
    // int medPower = 2;
    int maxPower = 3;
    int range = maxPower - minPower;
    // int powerRange = (power % range) + minPower;
    int powerRange(int sides) {
            return rand() % sides + 1;
            }

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
        cout << "I am " << name << " and i have " << health << " "; 
        cout << "health and " << energy << " energy remaining, and I do ";
        cout <<  damage << " "  << status() << " damage.\n";
    }

    void eatLemon(){
        cout << "my damage and energy was raised by 5!\n";
        basicWurm::damage += damage * 1.5;
        basicWurm::energy += energy * 0 + 5;
    }

    void eatCherry(){
        cout << "my health and energy was raised by 5!\n";
        basicWurm::health += health * 1.5;
        basicWurm::energy += energy * 0 + 5;
    }

    void eatMango(){
        cout << "my energy is raised 10!\n";
        basicWurm::energy += energy * 0 + 10;
    }

    void doSquiggle(){
        cout << "I am squiggling!\n";
        basicWurm::damage += powerRange(3);
        basicWurm::energy -=  powerRange(3);
        cout << "I squiggled and got a damage boost!\n";

    }

    void doSquirm(){
        cout << "I am squirming!\n";
        basicWurm::health += powerRange(3);
        basicWurm::energy -= powerRange(3);
        cout << "I squirmed and gained health!\n";

    }

    void doRead(string path = "worms.txt"){
     string line;
    ifstream readFile("worms.txt");
    if(readFile.is_open()){
        cout << "The crowd whoops in support!\n";
        while(getline(readFile, line)) {
            cout << line << endl;
        }
    }
    else{
        cout << "Couldnt open the file";
    }

    readFile.close();
}

void doRead(vector<string>& vec, string path = "worms.txt"){
    string line;
    ifstream readFile(path);
    if(readFile.is_open()) {
        while(getline(readFile, line)) {
            vec.push_back(line);
        }
    }   
    else{
        cout << "Couldnt open the file";
    }
    readFile.close();
}

    void write(vector<string>& vec, string path = "worms.txt"){
    cout << "starting write() function.\n";
    ofstream writerFile(path);
    if(writerFile.is_open()){
        cout << "opening the write file.\n";
        for(int i = 0; i < vec.size(); i++){
            writerFile << vec[i] << endl;
        }
    }
    else {
        cout << "couldnt open new writeFile.\n";
    }
}

    void haveEnergy(){
        cout << "I have " << energy << " energy remaining. ";
        cout << "I am ";

        if (energy < 0) cout << "unable";
        else if (energy < 5) cout << "not ready";
        else if (energy < 10) cout << "somewhat ready";
        else if (energy < 15) cout << "ready";
        else cout << "super ready";

        cout << " to fight.\n";
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
    
    basicWurm::energy += -5;

        // if(opponent.health <= 0) return true;
        // else                     return false;
    }
    };

int main(){
    srand(time(0));
    vector<string> worms;
    string input = "wormy";
    string path = "worms.txt";
    

    // wormys gaining their dirt element and introducing themselves
    basicWurm grandwurm;
    grandwurm.name = "Grand Wurm";
    grandwurm.typing = basicWurm::Type::SOIL;
    grandwurm.speakElement();

    basicWurm rampage;
    rampage.name = "Drakon King";
    rampage.typing = basicWurm::Type::CLAY;
    rampage.health = 500;
    rampage.damage = (rand() % 15) + 1;
    rampage.speakElement();

    do {
    string input; 
    cout << "What would you like to do?.\n";
    cout << "Train\n";
    cout << "Feed\n";
    cout << "Battle\n";
    cout << "Stats\n";
    cout << "Quit\n";

    grandwurm.haveEnergy();

    if (grandwurm.health <= 0 || grandwurm.energy <= 0 || grandwurm.energy >= 50){
        cout << "the wurm has died :((\n";
        cout << "thanks for playing!\n";

        break;
        } 

        else{
        cout << grandwurm.health << " health remaining and " << grandwurm.energy << " energy remaining!\n";
        }

    getline(cin, input);
    // Start of Attack

    if(input == "battle"){
        
            if(grandwurm.energy >= 5 || grandwurm.health >= 0){
                cout << "Would you like to fight, eat, or run away?\n";

                cin >> input;

                if(input == "fight"){
                cout << "The Grand Wurm readies its spell\n";
                grandwurm.attack(rampage);

                grandwurm.doRead();
                grandwurm.doRead(worms); 

                cout << "The Drakon King unleashes a breath attack!\n";
                rampage.attack(grandwurm);
                }

                else if(input == "fight" && grandwurm.energy <= 5){
                        cout << "I am too tired to fight, I need to be feed.";
                }

                else if(input == "eat"){
                cout << "what would you like to feed your worm?\n";
                    cout << "Lemon\n";
                    cout << "Cherry\n";
                    cout << "Mango\n";

                    cin >> input;

                    if (input == "lemon"){
                        cout << "oouu sour!\n";
                        grandwurm.eatLemon();
                    }
                    else if (input == "cherry"){
                        cout << "oouu tart!\n";
                        grandwurm.eatCherry();
                    }
                    else if (input == "mango"){
                        cout << "oouu sweet!\n";
                        grandwurm.eatMango();
                    }
                    else {
                        break;
                    }
                    }
            
                else if(input == "run"){
                    break;
                }

                else {
                    cout << "I do not understand?";
                    break;
                }
            }
            
            else   {
                cout << "you ran away from battle!";
                break;
            }
    }

    // Start of Feed
    else if(input == "feed") {
        cout << "what would you like to feed your worm?\n";
        cout << "Lemon\n";
        cout << "Cherry\n";
        cout << "Mango\n";

        cin >> input;

        if (input == "lemon"){
            cout << "oouu sour!\n";
            grandwurm.eatLemon();
        }
        else if (input == "cherry"){
            cout << "oouu tart!\n";
            grandwurm.eatCherry();
        }
        else if (input == "mango"){
            cout << "oouu sweet!\n";
            grandwurm.eatMango();
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
        cout << "lets add new worms to the audience!";
    //     cout << "What file would you like to open?\nEnter to do the defeult.\n";
    //     getline(cin, input);
    //     if(input != "no") {
    //     path = input;
    //     }

        grandwurm.doRead();
        grandwurm.doRead(worms);

        while(input != "") {
        cout << "> ";
        getline(cin, input);
        if(input == "");
    }

    worms.push_back(input);

    grandwurm.write(worms, path);

    }

    else {
        cout << "sorry I do not recoginze that?\n";
    }


    } while(true);

         return 0;
    } 

   