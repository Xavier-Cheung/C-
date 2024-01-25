#include<iostream>
#include"Circle.h"

using namespace std;

Circle::Circle() {
    cout << "这是Circle类的构造函数,默认圆心为(0,0),半径为0" << endl;
    this -> center.x = 0;
    this -> center.y = 0;
    this -> r = 0;
}

Circle::Circle(int a, int b, int c) {
    cout << "这是Circle类的含参(3)构造函数" << endl;
    this -> center.x = a;
    this -> center.y = b;
    this -> r = c;
}

Circle::Circle(Point& q, int c) {
    cout << "这是Circle类的含参(2)构造函数" << endl;
    this -> center.x = q.x;
    this -> center.y = q.y;
    this -> r = c;
}

Circle::~Circle() {
    cout << "这是Circle类的析构函数" << endl;
}