#include <iostream>
using namespace std;

class Rectangle
{
private:
    int len;
    int wid;

public:
    void setData(int l, int w)
    {
        len = l;
        wid = w;
    }
    int area()
    {
        return len * wid;
    }
    int perimeter()
    {
        return 2 * (len + wid);
    }
};

int main()
{
    Rectangle r1;
    int l, w;
    cout << "Enter length and width: ";
    cin >> l >> w;
    r1.setData(l, w);
    cout << "Area: " << r1.area() << endl;
    cout << "Perimeter: " << r1.perimeter() << endl;
    return 0;
}