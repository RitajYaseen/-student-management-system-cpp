#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

class Student {
public:
    int id;
    string name;
    int age;
    float gpa;

    void input() {
        cout << "Enter ID: ";
        cin >> id;
        cout << "Enter Name: ";
        cin >> name;
        cout << "Enter Age: ";
        cin >> age;
        cout << "Enter GPA: ";
        cin >> gpa;
    }

    void display() const {
        cout << "ID: " << id
            << " | Name: " << name
            << " | Age: " << age
            << " | GPA: " << gpa << endl;
    }
};

void addStudent() {
    Student s;
    s.input();

    ofstream file("students.txt", ios::app);
    file << s.id << " " << s.name << " "
        << s.age << " " << s.gpa << endl;
    file.close();
}

void displayStudents() {
    ifstream file("students.txt");
    Student s;

    while (file >> s.id >> s.name >> s.age >> s.gpa) {
        s.display();
    }

    file.close();
}

int main() {
    int choice;

    do {
        cout << "\n1. Add Student\n";
        cout << "2. Display Students\n";
        cout << "3. Exit\n";
        cout << "Choose: ";
        cin >> choice;

        switch (choice) {
        case 1: addStudent(); break;
        case 2: displayStudents(); break;
        }

    } while (choice != 3);

    return 0;
}
