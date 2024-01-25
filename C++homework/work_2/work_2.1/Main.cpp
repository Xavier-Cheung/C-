#include<iostream>
#include"Circle.h"


using namespace std;

int main() 
{
	system("chcp 65001");
    Circle C1, C2;
    //两个圆的参数输入
	cout << "请输入C1的圆心坐标" << endl;
	cin>>C1.center.x >> C1.center.y;
	cout << "请输入C1的半径" << endl;
	cin >> C1.r;
	cout << "请输入C2的圆心坐标" << endl;
	cin >> C2.center.x >> C2.center.y;
	cout << "请输入C2的半径" << endl;
	cin >> C2.r;
    //判断两圆的位置关系
	double distance =C1.center.Distance(C1.center.x, C1.center.y, C2.center.x, C2.center.y);
	if (distance > C1.r + C2.r)
		cout << "两圆外离" << endl;
	else if (distance == C1.r + C2.r)
		cout << "两圆外切" << endl;
	else if (distance == abs(C1.r - C2.r))
		cout << "两圆内切" << endl;
	else if (distance < abs(C1.r - C2.r))
		cout << "两圆内含" << endl;
	else 
        cout << "两圆相交" << endl;
    return 0;
}
//类的组合，构造函数先调用里面的，按顺序，最后是本类的构造函数，析构相反