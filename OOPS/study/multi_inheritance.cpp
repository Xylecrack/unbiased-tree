// perspn,employee,manager

#include <iostream>
using namespace std;

class person
{
protected:
    string name;
    int age;

public:
    person(string name, int age)
    {
        this->name = name;
        this->age = age;
    }
    void disp_person()
    {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
    }
};
class employee : public person
{
protected:
    int emp_id;
    float salary;

public:
    employee(string name, int age, int emp_id, float salary) : person(name, age)
    {
        this->emp_id = emp_id;
        this->salary = salary;
    }
};
