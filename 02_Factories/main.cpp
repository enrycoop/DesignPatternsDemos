#include <iostream>
#include <cmath>

using namespace std;


enum class PointType
{
    cartesian,
    polar
};

struct Point
{
    float x, y;

    //! 
    //! @param a this is either x or rho
    //! @param b this is eeither y or theta
    //! @param type 
    Point(float a, float b, PointType type = PointType::cartesian)
    {
        if (type == PointType::cartesian)
        {
            x = a;
            y = b;
        } else
        {
            x = a * cos(b);
            y = a * sin(b);
        }
    }
};

int main()
{
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
