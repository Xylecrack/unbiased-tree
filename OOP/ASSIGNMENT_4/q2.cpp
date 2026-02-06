#include <iostream>
#include <string>

using namespace std;

// Base class Person
class Person
{
  protected:
    string name;
    string dob; // Date of birth in the format "DD-MM-YYYY"

  public:
    Person(string name, string dob) : name(name), dob(dob)
    {
    }

    int calcAge(int currentYear) const
    {
        int birthYear = stoi(dob.substr(dob.length() - 4));
        return currentYear - birthYear;
    }

    void displayPersonDetails(int currentYear) const
    {
        cout << "Name: " << name << endl;
        cout << "Date of Birth: " << dob << endl;
        cout << "Age: " << calcAge(currentYear) << " years" << endl;
    }
};

// Derived class Employee from Person (Multilevel Inheritance)
class Employee : public Person
{
  protected:
    string eid;

  public:
    Employee(string name, string dob, string eid) : Person(name, dob), eid(eid)
    {
    }

    void displayEmployeeDetails(int currentYear) const
    {
        displayPersonDetails(currentYear);
        cout << "Employee ID: " << eid << endl;
    }
};

// Derived class Teacher from Employee (Multilevel Inheritance)
class Teacher : public Employee
{
  protected:
    string subject;
    string semester;

  public:
    Teacher(string name, string dob, string eid, string subject, string semester)
        : Employee(name, dob, eid), subject(subject), semester(semester)
    {
    }

    void displayTeacherDetails(int currentYear) const
    {
        displayEmployeeDetails(currentYear);
        cout << "Subject: " << subject << endl;
        cout << "Semester: " << semester << endl;
    }
};

// Base class Student
class Student
{
  protected:
    string roll;
    double cgpa;

  public:
    Student(string roll, double cgpa) : roll(roll), cgpa(cgpa)
    {
    }

    void displayStudentDetails() const
    {
        cout << "Roll Number: " << roll << endl;
        cout << "CGPA: " << cgpa << endl;
    }
};

// Derived class TeachingAssistant from Student and Teacher (Multiple Inheritance)
class TeachingAssistant : public Student, public Teacher
{
  public:
    TeachingAssistant(string name, string dob, string eid, string subject, string semester, string roll, double cgpa)
        : Student(roll, cgpa), Teacher(name, dob, eid, subject, semester)
    {
    }

    void displayTeachingAssistantDetails(int currentYear) const
    {
        displayTeacherDetails(currentYear);
        displayStudentDetails();
    }
};

int main()
{
    int currentYear = 2024;

    TeachingAssistant ta("Bob Brown", "01-01-1990", "E123", "Computer Science", "Fall 2024", "S456", 3.8);
    ta.displayTeachingAssistantDetails(currentYear);

    return 0;
}