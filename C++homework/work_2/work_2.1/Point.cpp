#include<iostream>
#include<math.h>
#include"Point.h"

using namespace std;

Point::Point() {
    cout << "这是Point类的构造函数,默认值为(0,0)" << endl;
    this -> x = 0;
    this -> y = 0;
}

Point::Point(int a, int b) {
    cout << "这是Point类的含参构造函数" << endl;
    this -> x = a;
    this -> y = b;
}

Point::Point(Point& q) {
    cout << "这是Point类的拷贝构造函数" << endl;
    this -> x = q.x;
    this -> y = q.y;
}

Point::~Point() {
    cout << "这是Point类的析构函数" << endl;
}

double Point::Distance (int x1, int y1, int x2, int y2) {
    return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}