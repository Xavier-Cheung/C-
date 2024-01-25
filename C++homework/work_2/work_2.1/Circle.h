#include"Point.h"

class Circle
{
public:
    Point center;
    int r;
    Circle();
    Circle(int a, int b, int c);
    Circle(Point& q, int c);
    ~Circle();
};


