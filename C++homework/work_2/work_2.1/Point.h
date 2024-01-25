class Point
{
public:
    int x, y;
    double Distance(int x1, int y1, int x2, int y2);
    Point();
    Point(int a, int b);
    Point(Point& q);
    ~Point();
};
