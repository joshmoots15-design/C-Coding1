// Josh Moots Spr26
// Writing to and reading from files

#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

void read(string path = "save.txt"){
     string line;
    ifstream readFile("save.txt");
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

void read(vector<string>& vec, string path = "save.txt"){
    string line;
    ifstream readFile(path);
    if(readFile.is_open()) {
        cout << "The file is open.\n";
        while(getline(readFile, line)) {
            vec.push_back(line);
        }
    }   
    else{
        cout << "Couldnt open the file";
    }
    readFile.close();
}

void write(vector<string>& vec, string path = "save.txt"){
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

int main() {
    cout << "its file time!\n";
    vector<string> favs; 
    string input = "asdf";

    string path = "save.txt";
    cout << "What file would you like to open?\nEnter to do the defeult.\n";
    getline(cin, input);
    if(input != "no") {
        path = input;
    }

    read();
    read(favs);

    cout << "What names would you like?\n";
    cout << "enter an empty line to stop?\n";

    

    while(input != "") {
        cout << "> ";
        getline(cin, input);
        if(input == "");
            break;
        // writerFile << input << endl;
        break;
    }

    favs.push_back(input);

    write(favs, path);

    return 0;
}