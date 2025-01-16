#include <iostream>
#include <string>

using namespace std;

struct Employee
{
    int eid;
    string ename;
    int no_of_hours[7];
};

int calculateTotalHours(const Employee& emp)
{
    int total = 0;
    for (int i = 0; i < 7; i++)
    {
        total += emp.no_of_hours[i];
    }
    return total;
}

double calculateAverageHours(const Employee& emp)
{
    return static_cast<double>(calculateTotalHours(emp)) / 7;
}

void input(Employee& emp)
{
    cout << "Enter employee id: ";
    cin >> emp.eid;

    cout << "Enter employee name: ";
    cin.ignore();
    getline(cin, emp.ename);

    cout << "Enter number of hours worked on each day of the week: ";
    for (int i = 0; i < 7; i++)
    {
        cin >> emp.no_of_hours[i];
    }
}

void display(const Employee& emp)
{
    cout << "Employee id: " << emp.eid << endl;
    cout << "Employee name: " << emp.ename << endl;
    cout << "Number of hours worked on each day of the week: ";
    for (int i = 0; i < 7; i++)
    {
        cout << emp.no_of_hours[i] << " ";
    }
    cout << endl;
    cout << "Total hours worked: " << calculateTotalHours(emp) << endl;
    cout << "Average hours worked: " << calculateAverageHours(emp) << endl;
}

int main()
{
    Employee employees[3];

    for (int i = 0; i < 3; i++)
    {
        cout << "Enter details for employee " << i + 1 << ":" << endl;
        input(employees[i]);
    }

    cout << endl;

    for (int i = 0; i < 3; i++)
    {
        cout << "Details of employee " << i + 1 << ":" << endl;
        display(employees[i]);
        cout << endl;
    }

    return 0;
}