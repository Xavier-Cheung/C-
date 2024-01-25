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
        cout << "����Shape��Ĺ��캯��" << endl;
    };
    ~Shape() {
        cout << "����Shape�����������" << endl;
    };
};

class Rectangle :public Shape
{
public:
    int x, y;
    Rectangle() {
        cout << "����Rectangle��Ĺ��캯��" << endl;
    }
    ~Rectangle() {
        cout << "����Rectangle�����������" << endl;
    }
};

class Circle :public Shape
{
public:
    int r;
    Circle() {
        cout << "����Circle��Ĺ��캯��" << endl;
    } 
    ~Circle() {
        cout << "����Circle�����������" << endl;
    }
};

class Square :public Rectangle
{
public:
    int a;
    Square() {
        cout << "����Square��Ĺ��캯��" << endl;
    }
    ~Square() {
        cout << "����Square�����������" << endl;
    }
};

int main() 
{
    cout << "����������Ķ���A" << endl;
    Rectangle A;
    cout << "������A�ĳ��Ϳ�:" << endl;
    cin >> A.x >> A.y;
    A.Cal_Area(A.x, A.y); 
    cout << "����A�����Ϊ: " << A.Area << endl;
    
    cout << "������������Ķ���B" << endl;
    Square B;
    cout << "������B�ı߳�:" << endl;
    cin >> B.a;
    B.Cal_Area(B.a, B.a); 
    cout << "����B�����Ϊ: " << B.Area << endl;

    cout << "����Բ����Ķ���C" << endl;
    Circle C;
    cout << "������C�İ뾶:" << endl;
    cin >> C.r;
    C.Cal_Area(C.r); 
    cout << "����C�����Ϊ: " << C.Area << endl;
    return 0;
}

void Shape::Cal_Area(int x, int y) {
    this -> Area = x * y;
}

void Shape::Cal_Area(int r) {
    this -> Area = PI * r * r;
}
