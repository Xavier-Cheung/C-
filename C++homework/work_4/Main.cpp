#include<iostream>
#include<string>
#include<cstdlib>
#include<ctime>

using namespace std;

int main()
{
    cout << "��ʼ���¼۸���Ϸ" << endl;
    srand((unsigned)time(NULL));
    int Price = (rand() % 1000) + 1;//����[1,1000]��Χ�ڵ��������Ϊ�۸�
    int Try_price;
    cout << "�����뾺�¼۸�";
    cin >> Try_price;
    if (Try_price > 1000 || Try_price < 1 || cin.fail())
    {
        if (cin.fail())//���벻�Ϸ�
        {
            cin.clear(); //���std::cin�Ĵ���״̬
            cin.sync(); //������뻺����
            cin.ignore(10000, '\n');//����������س�֮ǰ�����ݻ��߻�����ǰ10000λ����

        }
        cout << "���µļ۸�����Ʒ�۸���ܵ����䷶Χ��,��Ʒ�ļ۸�����Ϊ[1,1000]" << endl;
        cout << "���ٴ����뾺�¼۸�";
        cin >> Try_price;
    }
    while (Try_price != Price)
    {
        if (Try_price > Price && Try_price <= 1000 && Try_price > 0)
            cout << "���µļ۸�����ˣ�" << endl;
        else if (Try_price < Price && Try_price <= 1000 && Try_price > 0)
            cout << "���µļ۸�����ˣ�" << endl;
        else 
            cout << "���µļ۸�����Ʒ�۸�������䷶Χ�ڣ���Ʒ�ļ۸�����Ϊ[1,1000]" << endl;
        cout << "���ٴ����뾺�¼۸�";
        cin >> Try_price;
    }
    cout << "��ϲ���¶��ˣ���������" << endl;

	return 0;
}
