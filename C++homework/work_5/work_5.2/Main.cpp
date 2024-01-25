#include<iostream>

using namespace std;

class Point
{
public:
    int x, y;

    //前置++
    Point& operator++() {
        this -> x += 1;
        this -> y += 1;
        return *this;
    }

    //前置--
    Point& operator--() {
        this -> x -= 1;
        this -> y -= 1;
        return *this;
    }

    //后置++
    Point operator++(int) {
        Point temp = *this;
        this -> x += 1;
        this -> y += 1;
        return temp;
    }

    //后置--
    Point operator--(int) {
        Point temp = *this;
        this -> x -= 1;
        this -> y -= 1;
        return temp;
    }
    Point();
    Point(int a, int b);
    ~Point();
};

Point::Point() {
    this -> x = 0;
    this -> y = 0; 
}

Point::Point(int a, int b) {
    this -> x = a;
    this -> y = b;
}
Point::~Point() {}

int main() 
{
    Point A;
    cout << "请输入点A的横纵坐标:" << endl;
    cin >> A.x >> A.y;
    cout << "A现在的坐标:(" << A.x <<" " << A.y << ")" << endl;
	cout << "A++的坐标:(" << A++.x <<" " << A.y - 1<< ")" << endl;
    cout << "A现在的坐标:(" << A.x <<" " << A.y << ")" << endl;
	cout << "++A的坐标:(" << (++A).x <<" " << A.y << ")" << endl;
	cout << "A现在的坐标:(" << A.x <<" " << A.y << ")" << endl;
    return 0;
}
