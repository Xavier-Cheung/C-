#include<iostream>
#include"Matrix.h"

using namespace std;

int main()
{
    int Rows, Lines;
    cout << "请输入矩阵的行数和列数:" << endl;
    cin >> Rows >> Lines;
    //创建三个矩阵，在构造函数内就已经申请好了空间
    Matrix A1(Rows, Lines);
    Matrix A2(Rows, Lines);
    Matrix A3(Rows, Lines);
    cout << "请输入矩阵A1:" << endl;
    A1.Input();
    cout << "请输入矩阵A2:" << endl;
    A2.Input();

    A3.Addition(A1, A2);
    cout << "矩阵A3 = A1 + A2 如下:" << endl;
    A3.Output();

    A3.Subtract(A1, A2);
    cout << "矩阵A3 = A1 - A2 如下:" << endl;
    A3.Output();

    //使用new动态申请矩阵类的对象
    Matrix* pA1 = new Matrix (A1);
    Matrix* pA2 = new Matrix (A2);
    Matrix* pA3 = new Matrix (A3);
    pA3 -> Addition(*pA1, *pA2);
    cout << "矩阵pA3 = pA1 + pA2 如下:" << endl;
    pA3 -> Output();
    pA3 -> Subtract(*pA1, *pA2);
    cout << "矩阵pA3 = pA1 - pA2 如下:" << endl;
    pA3 -> Output();

    delete pA1;
    delete pA2;
    delete pA3;

    return 0;
}