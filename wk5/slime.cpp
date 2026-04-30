// Josh Moots Spr26
// Slimed!

#include <iostream>
#include <string>           // for getline()
#include <vector>           // for vectors and iterators
#include <ctime> 
#include <cstdlib>
#include <algorithm>

using namespace std;

vector<string> names = {"Mini ", "Tiny ", "Smol ", "Lil ", "Teeny ", "Itsy "};

class baseSlime{
public:
    string name;
    int health;
    int damage;

    baseSlime() {
        cout << "A new slime has been summoned.\n";
        name = names[rand() % names.size()] + "slime";
        health = 5;
        damage = 3;
    }

    void hello(){
        cout << "Remeber the name: " << name << ". I am at " << health << " health. And I will do " << damage << " damage.\n";
    }

    bool attack(baseSlime& opponent) {
        opponent.health -= damage;
        cout << name << " has done " << damage << " damage to ";
        cout << opponent.name << "!\n";

        if(opponent.health <= 0) return true;
        else                     return false;
    }

};

class bossSlime : public baseSlime {
public:
    int damageMulti = 3;

    bossSlime(){
        name = "boss";
        damage = damage * damageMulti;
    }

    bool attack(baseSlime& opponent) {
        cout << "The King drops the hammer!\n";
        opponent.health -= damage;
        cout << name << " has done " << damage << " damage to ";
        cout << opponent.name << "!\n";

        if(opponent.health <= 0) return true;
        else                     return false;
    }

    void taunt() {
        cout << "When draw near your fianl breath, worm, the last thing you will see is me.\n";
    }
};

int main(){
    srand(time(0));
    cout << "Imma slime ya big dawg >:(\n";

    baseSlime gerald;
    gerald.name = "Mini Ooze";
    gerald.hello();

    bossSlime destoryer;
    destoryer.name = "King Slime";
    destoryer.hello();
    destoryer.taunt();

    cout << "Mini Ooze is feeling fiesty...\n";
    gerald.attack(destoryer);

    cout << "The King raises his pseudopod in retaliation!\n";
    if (destoryer.attack(gerald)) {
        cout << gerald.name << " is reduced to pulp.\n";
    }

    vector<baseSlime> sludge(6);

    cout << "Here is our sludge of slimes:\n\n";
    for(auto& slime : sludge) {
        cout << slime.name << "\n";
    }

    random_shuffle(sludge.begin(), sludge.end());

    auto& a = sludge[0];
    auto& b = sludge[1];
    auto& c = sludge[2];
    auto& d = sludge[3];
    auto& e = sludge[4];
    auto& f = sludge[5];

    cout << a.name << " is in a heated battle with " << b.name << "!\n";

    while(a.health > 0 && b.health > 0) {
        if(a.attack(b)) {
            cout << b.name << " has fallen to the hand of " << a.name << ".\n";
        }
        else {
            if(b.attack(a)) {
                cout << a.name << " has fallen to the hand of " << b.name << ".\n";
            }
        }
    }

    return 0;
}