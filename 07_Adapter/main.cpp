#include <iostream>
#include "Geometry.h"

using namespace std;

int main()
{
    vector<shared_ptr<VectorObject>> vectorObjects{
        std::make_shared<VectorRectangle>(10, 10, 100, 100),
        std::make_shared<VectorRectangle>(30, 30, 60, 60),
    };

    return 0;
}
