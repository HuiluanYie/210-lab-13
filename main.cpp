// COMSC-210 | Lab 13 | Huiluan Yie

#include <iostream>
#include <array>
#include <fstream>
using namespace std;

struct Student {
    // the Student struct contain the student ID and exam score
    long ID;
    int score;
};

const int NUM = 150;

//Function prototype


int main() {
    // declarations
    array < Student, NUM > students;
    string file = "210-lab-13-grades.txt";

    // file input
    ifstream fin;
    fin.open(file);
    if (fin.good()) {
        for (int i = 0; i < NUM; i++)
        {
            /* code */
        }
        


        cout << "Read " << NUM <<" student records"
        fin.close(); // close the file
    }
    else
        cout << "File not found.\n";


    return 0;
}

//Function definition
