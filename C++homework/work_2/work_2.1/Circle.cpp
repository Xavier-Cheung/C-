#include<iostream>
#include"Circle.h"

using namespace std;

Circle::Circle() {
    cout << "����Circle��Ĺ��캯��,Ĭ��Բ��Ϊ(0,0),�뾶Ϊ0" << endl;
    this -> center.x = 0;
    this -> center.y = 0;
    this -> r = 0;
}

Circle::Circle(int a, int b, int c) {
    cout << "����Circle��ĺ���(3)���캯��" << endl;
    this -> center.x = a;
    this -> center.y = b;
    this -> r = c;
}

Circle::Circle(Point& q, int c) {
    cout << "����Circle��ĺ���(2)���캯��" << endl;
    this -> center.x = q.x;
    this -> center.y = q.y;
    this -> r = c;
}

Circle::~Circle() {
    cout << "����Circle�����������" << endl;
}