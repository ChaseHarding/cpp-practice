// gradebook.cpp
// Reads a student's name and 5 test scores, then reports the
// average, highest, lowest, and a letter grade.

#include <iostream>
#include <string>
using namespace std;

const int NUM_SCORES = 8;

// Returns the average of the scores in the array
double calcAverage(const double scores[], int size) {
    double sum = 0;
    for (int i = 0; i < size; i++) {
        sum += scores[i];
    }
    return sum / size;
}

// Returns the highest score
double findHighest(const double scores[], int size) {
    double highest = scores[0];
    for (int i = 1; i < size; i++) {
        if (scores[i] > highest) {
            highest = scores[i];
        }
    }
    return highest;
}

// Returns the lowest score
double findLowest(const double scores[], int size) {
    double lowest = scores[0];
    for (int i = 1; i < size; i++) {
        if (scores[i] < lowest) {
            lowest = scores[i];
        }
    }
    return lowest;
}

// Converts a numeric average to a letter grade
char letterGrade(double average) {
    if (average >= 90) return 'A';
    else if (average >= 80) return 'B';
    else if (average >= 70) return 'C';
    else if (average >= 60) return 'D';
    else return 'F';
}

int main() {
    string name;
    double scores[NUM_SCORES];

    cout << "Enter student name: ";
    getline(cin, name);

    for (int i = 0; i < NUM_SCORES; i++) {
        cout << "Enter score " << (i + 1) << ": ";
        cin >> scores[i];
    }

    double avg = calcAverage(scores, NUM_SCORES);

    cout << "\nReport for " << name << "\n";
    cout << "Average: " << avg << "\n";
    cout << "Highest: " << findHighest(scores, NUM_SCORES) << "\n";
    cout << "Lowest:  " << findLowest(scores, NUM_SCORES) << "\n";
    cout << "Grade:   " << letterGrade(avg) << "\n";

    return 0;
}
