#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>

using namespace std;

class Point
{
    friend class PointFactory; // OCP
    Point(float x, float y) : x(x), y(y) {}
public:
    float x, y;
    friend std::ostream& operator<<(std::ostream& os, const Point& obj)
    {
        return os << "x: " << obj.x << " y: " << obj.y;
    }
};

class PointFactory
{
public:
    static Point NewCartesian(float x, float y)
    {
        return {x, y};
    }
    static Point NewPolar(float r, float theta)
    {
        return {r * cos(theta), r * sin(theta)};
    }
};

int main()
{
    Point p = PointFactory::NewPolar(5, M_PI_4);
    cout << p << endl;
    return 0;
}
