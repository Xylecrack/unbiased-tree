#include <iostream>
#include <cmath>
using namespace std;

class Point
{
private:
    int x, y;

public:
    Point() : x(0), y(0) {}

    Point(int a, int b) : x(a), y(b) {}

    void display() const
    {
        cout << "Point: (" << x << ", " << y << ")" << endl;
    }

    double length(const Point &p) const
    {
        return sqrt(pow(x - p.x, 2) + pow(y - p.y, 2));
    }
};

int main()
{
    Point p1(1, 2), p2(3, 4);
    p1.display();
    p2.display();
    cout << "Length between p1 and p2: " << p1.length(p2) << endl;

    return 0;
}
