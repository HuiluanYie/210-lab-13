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
void sort_by_ID(array < Student, NUM >&);
void sort_by_score(array < Student, NUM >&);

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
        fin.close(); // close the file for input
        print(students);

        // perform selection sort and output to file
        sort_by_ID(students);
        ofstream fout; 
        fout.open(out_file);
        fout << "The sorted student data";
        for (Student s : students)
        {
            fout << "\nstudent ID: " << s.ID << endl;
            fout << "student score: " << s.score << endl;
        }
        fin.close(); // close the file for output
        cout << "Sorted results written to " << out_file;

        //Statistics calculations
        // find median
        sort_by_score(students);

        int median_index = students.size() / 2;
        // find mean score
        double sum = 0;
        for (Student s:students) {
            sum += s.score;
        }
        double mean = sum / students.size();
        
        // find standard deviation of scores
        double sum_sd = 0;
        for (Student s:students) {
            double square_diff = pow(s.score - mean, 2);
            sum_sd += square_diff;
        } 
        double std = sqrt(sum_sd/(students.size()-1));

        //Output summary
        cout << "--- Summary Statistics ---\n";
        cout << "Minimum Score: " << students[0].score 
            << " (Student ID: " << students[0].ID << ")\n";
        cout << "Maximum Score: " << students[students.size() - 1].score 
            << " (Student ID: " << students[students.size() - 1].ID << ")\n";
        cout << "Mean Score: " << mean;
        cout << "Median Score: " << median;
Median Score: 80.5 (Student ID: 304367391)
Standard Deviation: 6.48554"
    }
    else
        cout << "File not found.\n";

    return 0;
}

//Function definition
void print(const array < Student, NUM >& students) {
    // print() outputs the student data in the array (for testing)
    // arguments: an array of Student
    // returns: none
    for (Student s : students)
    {
        cout << "\nstudent ID: " << s.ID << endl;
        cout << "student score: " << s.score << endl;
    }
}

void sort_by_ID(array < Student, NUM >& students) {
    // sort_by_ID() sort the student data by student ID using selection sort 
    // arguments: an array of Student
    // returns: none
    for (int i = 0; i < students.size() - 1; i++) {
        // Find index of smallest remaining element
        int index_smallest = i;
        for (int j = i + 1; j < students.size(); j++) {
            if (students[j].ID < students[index_smallest].ID) {
                index_smallest = j;
            }
        }
     
        // Swap students[i] and students[index_smallest]
        Student temp = students[i];
        students[i] = students[index_smallest];
        students[index_smallest] = temp;
   }
}

void sort_by_score(array < Student, NUM >& students) {
    // sort_by_score() sort the student data by student score using selection sort 
    // arguments: an array of Student
    // returns: none
    for (int i = 0; i < students.size() - 1; i++) {
        // Find index of smallest remaining element
        int index_smallest = i;
        for (int j = i + 1; j < students.size(); j++) {
            if (students[j].score < students[index_smallest].score) {
                index_smallest = j;
            }
        }
     
        // Swap students[i] and students[index_smallest]
        Student temp = students[i];
        students[i] = students[index_smallest];
        students[index_smallest] = temp;
   }
}