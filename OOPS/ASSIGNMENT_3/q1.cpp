#include <iostream>

class Mks_Dist;

class FPS_Dist
{
public:
    double inches;
    double feet;

    FPS_Dist(double inches, double feet){
        this->inches = inches;
        this->feet = feet;
    }

    friend void compareLength(const Mks_Dist &m, const FPS_Dist &i);
};

class Mks_Dist
{
private:
    double meters;
    double centimeters;

public:

    Mks_Dist(double meters, double centimeters){
        this->meters = meters;
        this->centimeters = centimeters;
    }

    friend void compareLength(const Mks_Dist &m, const FPS_Dist &i);
};

void compareLength(const Mks_Dist &m, const FPS_Dist &i)
{
    std::cout << "Meters: " << m.meters << " Centimeters: " << m.centimeters << std::endl;
    std::cout << "Feet: " << i.feet << " Inches: " << i.inches << std::endl;

    double mks = m.meters + m.centimeters / 100;
    double fps = i.feet + i.inches / 12;

    if (mks > fps)
    {
        std::cout << "Mks is greater" << std::endl;
    }
    else if (mks < fps)
    {
        std::cout << "Fps is greater" << std::endl;
    }
    else
    {
        std::cout << "Both are equal" << std::endl;
    }
}

int main()
{
    Mks_Dist m(6, 3);
    FPS_Dist i(3, 2);

    compareLength(m, i);

    return 0;
}