#include <iostream>
#include <string>
#include <cmath>
using namespace std;

class shape
{
private:
    string name;
    int sides;
    double a;
    int s1, s2, s3;
    double s, temp;

public:
    shape(double radius)
    {
        name = "circle";
        sides = 0;
        s1 = radius;
    }

    shape(int side)
    {
        name = "square";
        sides = 4;
        s1 = side;
    }

    shape(int length, int width)
    {
        name = "rectangle";
        sides = 4;
        s1 = length;
        s2 = width;
    }

    shape(int side1, int side2, int side3)
    {
        name = "triangle";
        sides = 3;
        s1 = side1;
        s2 = side2;
        s3 = side3;
    }

    void area()
    {
        if (sides == 0)
        {
            a = 3.14 * s1 * s1;
        }
        else if (name == "square")
        {
            a = s1 * s1;
        }
        else if (name == "rectangle")
        {
            a = s1 * s2;
        }
        else if (sides == 3)
        {
            s = (s1 + s2 + s3) / 2.0;
            temp = s * (s - s1) * (s - s2) * (s - s3);
            a = sqrt(temp);
        }
    }

    void display()
    {
        cout << "NAME = " << name << endl;
        cout << "sides = " << sides << endl;
        cout << "area = " << a << endl;
    }
};

int main()
{
    shape a(1.2);
    a.area();
    a.display();

    shape b(4);
    b.area();
    b.display();

    shape c(4, 5);
    c.area();
    c.display();

    shape d(3, 4, 5);
    d.area();
    d.display();

    return 0;
}