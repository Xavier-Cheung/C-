#include<iostream>
#include<string>
#include<cstdlib>
#include<ctime>

using namespace std;

int main()
{
    cout << "开始竞猜价格游戏" << endl;
    srand((unsigned)time(NULL));
    int Price = (rand() % 1000) + 1;//生成[1,1000]范围内的随机数作为价格
    int Try_price;
    cout << "请输入竞猜价格：";
    cin >> Try_price;
    if (Try_price > 1000 || Try_price < 1 || cin.fail())
    {
        if (cin.fail())//输入不合法
        {
            cin.clear(); //清除std::cin的错误状态
            cin.sync(); //清空输入缓冲区
            cin.ignore(10000, '\n');//清除缓冲区回车之前的数据或者缓冲区前10000位数据

        }
        cout << "您猜的价格不在商品价格可能的区间范围内,商品的价格区间为[1,1000]" << endl;
        cout << "请再次输入竞猜价格：";
        cin >> Try_price;
    }
    while (Try_price != Price)
    {
        if (Try_price > Price && Try_price <= 1000 && Try_price > 0)
            cout << "您猜的价格过高了！" << endl;
        else if (Try_price < Price && Try_price <= 1000 && Try_price > 0)
            cout << "您猜的价格过低了！" << endl;
        else 
            cout << "您猜的价格不在商品价格可能区间范围内，商品的价格区间为[1,1000]" << endl;
        cout << "请再次输入竞猜价格：";
        cin >> Try_price;
    }
    cout << "恭喜您猜对了！！！！！" << endl;

	return 0;
}
