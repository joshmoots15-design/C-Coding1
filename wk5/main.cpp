// Josh Moots Spr26
// Writing to and reading from files

#include <iostream>
#include <string>

using namespace std;

class robot {
private:
    string name;
    int charge;
    int boredom;

public:
    robot(string giveName, int giveCharge, int giveBoredom){
        name = giveName;
        charge = giveCharge;
        boredom = giveBoredom;
        status();
    }

    robot(){
        name = "robot";
        charge = 10;
        boredom = 10;
        status();
    }

    void status() {
        cout << "Hello my name is " << name;
        cout << " and my charge is " << charge << ".\n";
        cout << "I am ";

        if(boredom < 5) cout << "joyous!\n";
        else if (boredom < 10) cout << "blehh.\n";
        else if (boredom < 15) cout << "irked.\n";
        else cout << "cantankerous!\n";
    }

    string getName(){
        return name;
    }

    int getCharge(){
        return charge;
    }

    int getBoredom(){
        return boredom;
    }

    void setName(string giveName) {
        if(giveName.size() <= 5){
            name = giveName;
        }
        else {
            cout << "error: " << giveName << " is too long";
        }
    }

    void setCharge(int giveCharge) {
        if(giveCharge < 0) charge = 0;
        else if(giveCharge > 100) charge = 100;
        else charge = giveCharge;
        }

    void setBoredom (int giveBoredom){
        if(giveBoredom > 20) boredom = 20;
        boredom = giveBoredom;
    }

    void changeChargeBy (int amount = 1) {
        setCharge (charge += amount);
    }

};

int main(){
    cout << "Classes!\n";

    robot artoo("R2-D2", 45, 3);
    // artoo.name = "R2-D2";
    // artoo.charge = 45;
    // artoo.boredom = 3;
    cout << "artoo has " << artoo.getName().size() << " characters in their name.";

    robot threepio;
    threepio.setName("C-3P0");
    threepio.setCharge (2);
    threepio.setBoredom(12);

    artoo.status();
    threepio.status();

    cout << "threepio is low, artoo give him energy!\n";

    while(threepio.getCharge() < 15) {
        // artoo.setCharge(artoo.getCharge() - 1);
        // threepio.setCharge(threepio.getCharge() + 1)
        if(artoo.getCharge() > 0){
            artoo.changeChargeBy(-1);
            threepio.changeChargeBy(1);
        }
    }

    artoo.status();
    threepio.status();

    return 0;
}