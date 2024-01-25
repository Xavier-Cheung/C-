#include <iostream>
#include <cmath>
using namespace std;
#define PI 3.14

class Shape 
{
public:
    virtual double calArea() = 0;
    Shape() { cout << "这是Shape类的构造函数" << endl; }
    ~Shape() { cout << "这是Shape类的析构函数" << endl; }
};

class Rectangle :virtual public Shape 
{
public:
    int w, h;
    Rectangle(int a = 0, int b = 0) : w(a), h(b) { cout << "这是Rectangle类的构造函数" << endl; }
    ~Rectangle() { cout << "这是Rectangle类的析构函数" << endl; }
    double calArea() {
        return w * h;
    }
};

class Square :public Rectangle 
{
public:
    int a;
    Square(int a = 0) : a(a) { cout << "这是Square类的构造函数" << endl; }
    ~Square() { cout << "这是Square类的析构函数" << endl; }
    double calArea() {
        return a * a;
    }
};

class Circle :virtual public Shape
{
public:
    int r;
    Circle(int r = 0) : r(r) { cout << "这是Circle类的构造函数" << endl; }
    ~Circle() { cout << "这是Circle类的析构函数" << endl; }
    double calArea() {
        return PI * r * r;
    }
};

int main() {
    cout << "创建正方形类的对象" << endl;
    Square square;
    cout << "请输入正方形的边长" << endl;
    cin >> square.a;
    cout << "正方形的面积为：" << square.calArea() << endl;

    cout << endl;
    cout << "创建圆形类的对象" << endl;
    Circle circle;
    cout << "请输入圆形的半径" << endl;
    cin >> circle.r;
    cout << "圆形的面积为：" << circle.calArea() << endl;
    return 0;
}
