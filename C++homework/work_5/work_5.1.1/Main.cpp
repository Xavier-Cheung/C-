#include<iostream>
#define PI 3.14

using namespace std;

class Shape
{
public:
    double Area;
    virtual void Cal_Area(int r);
    virtual void Cal_Area(int x, int y);
    Shape() {
        cout << "这是Shape类的构造函数" << endl;
    };
    ~Shape() {
        cout << "这是Shape类的析构函数" << endl;
    };
};

class Rectangle :public Shape
{
public:
    int x, y;
    Rectangle() {
        cout << "这是Rectangle类的构造函数" << endl;
    }
    ~Rectangle() {
        cout << "这是Rectangle类的析构函数" << endl;
    }
};

class Circle :public Shape
{
public:
    int r;
    Circle() {
        cout << "这是Circle类的构造函数" << endl;
    } 
    ~Circle() {
        cout << "这是Circle类的析构函数" << endl;
    }
};

class Square :public Rectangle
{
public:
    int a;
    Square() {
        cout << "这是Square类的构造函数" << endl;
    }
    ~Square() {
        cout << "这是Square类的析构函数" << endl;
    }
};

int main() 
{
    cout << "创建矩形类的对象A" << endl;
    Rectangle A;
    cout << "请输入A的长和宽:" << endl;
    cin >> A.x >> A.y;
    A.Cal_Area(A.x, A.y); 
    cout << "计算A的面积为: " << A.Area << endl;
    
    cout << "创建正方形类的对象B" << endl;
    Square B;
    cout << "请输入B的边长:" << endl;
    cin >> B.a;
    B.Cal_Area(B.a, B.a); 
    cout << "计算B的面积为: " << B.Area << endl;

    cout << "创建圆形类的对象C" << endl;
    Circle C;
    cout << "请输入C的半径:" << endl;
    cin >> C.r;
    C.Cal_Area(C.r); 
    cout << "计算C的面积为: " << C.Area << endl;
    return 0;
}

void Shape::Cal_Area(int x, int y) {
    this -> Area = x * y;
}

void Shape::Cal_Area(int r) {
    this -> Area = PI * r * r;
}
