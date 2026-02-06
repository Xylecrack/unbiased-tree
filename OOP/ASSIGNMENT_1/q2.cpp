#include <iostream>
#include <string>

using namespace std;

class Student {
private:
    string studentName;
    int rollNumber;
    float subject1, subject2, subject3;

public:
    void input() {
        cout << "Enter name: ";
        cin >> studentName;
        cout << "Enter roll number: ";
        cin >> rollNumber;
        cout << "Enter marks in 3 subjects: ";
        cin >> subject1 >> subject2 >> subject3;
    }

    void display() {
        cout << "Name: " << studentName << endl;
        cout << "Roll number: " << rollNumber << endl;
        cout << "Marks: " << subject1 << " " << subject2 << " " << subject3 << endl;
        cout << "Average: " << calculate() << endl;
    }

    float calculate() {
        return (subject1 + subject2 + subject3) / 3;
    }
};

int main() {
    Student students[5];

    for (int i = 0; i < 5; i++) {
        cout << "Enter details for student " << i + 1 << ":" << endl;
        students[i].input();
    }

    cout << endl;

    for (int i = 0; i < 5; i++) {
        cout << "Details of student " << i + 1 << ":" << endl;
        students[i].calculate();
        students[i].display();
        cout << endl;
    }

    return 0;
}
