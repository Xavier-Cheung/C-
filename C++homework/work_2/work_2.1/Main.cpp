#include<iostream>
#include"Circle.h"


using namespace std;

int main() 
{
	system("chcp 65001");
    Circle C1, C2;
    //����Բ�Ĳ�������
	cout << "������C1��Բ������" << endl;
	cin>>C1.center.x >> C1.center.y;
	cout << "������C1�İ뾶" << endl;
	cin >> C1.r;
	cout << "������C2��Բ������" << endl;
	cin >> C2.center.x >> C2.center.y;
	cout << "������C2�İ뾶" << endl;
	cin >> C2.r;
    //�ж���Բ��λ�ù�ϵ
	double distance =C1.center.Distance(C1.center.x, C1.center.y, C2.center.x, C2.center.y);
	if (distance > C1.r + C2.r)
		cout << "��Բ����" << endl;
	else if (distance == C1.r + C2.r)
		cout << "��Բ����" << endl;
	else if (distance == abs(C1.r - C2.r))
		cout << "��Բ����" << endl;
	else if (distance < abs(C1.r - C2.r))
		cout << "��Բ�ں�" << endl;
	else 
        cout << "��Բ�ཻ" << endl;
    return 0;
}
//�����ϣ����캯���ȵ�������ģ���˳������Ǳ���Ĺ��캯���������෴