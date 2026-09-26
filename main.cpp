// COMSC-210 | Lab 13 | Huiluan Yie

#include <iostream>
#include <array>
#include <fstream>
#include <string>
using namespace std;

struct Student {
    // the Student struct contain the student ID and exam score
    long ID;
    double score;
};

const int NUM = 150;

//Function prototype
void print(const array < Student, NUM >&);

int main() {
    // declarations
    array < Student, NUM > students;
    string in_file = "210-lab-13-grades.txt";
    string out_file = "210-lab-13-grades-sorted.txt";

    // file input
    ifstream fin;
    fin.open(in_file);
    if (fin.good()) {
        for (int i = 0; i < NUM; i++)
        {
            fin >> students[i].ID;
            fin >> students[i].score;
        }
        cout << "Read " << students.size() <<" student records";
        fin.close(); // close the file

        print(students);



    }
    else
        cout << "File not found.\n";


    return 0;
}

//Function definition
void print(const array < Student, NUM >& students) {
    // print() outputs the student data in the array
    // arguments: an array of Student
    // returns: none
    for (Student s : students)
    {
        cout << "\nstudent ID: " << s.ID << endl;
        cout << "student score: " << s.score << endl;
    }
}

void selection_sort(array < Student, NUM >& students) {
    for (int i = 0; i < students.size() - 1; i++) {
        // Find index of smallest remaining element
        int index_smallest = i;
        for (int j = i + 1; j < students.size(); j++) {
        }
}