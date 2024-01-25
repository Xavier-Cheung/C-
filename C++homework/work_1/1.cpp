#include<iostream>
using namespace std;

#define ROW 4
#define COL 5

void M_init(int**& A);//初始化矩阵
void M_addition(int** A1, int** A2, int** A3);//实现两个矩阵相加
void M_subtraction(int** A1, int** A2, int** A3);//实现两个矩阵相减
void M_output(int** A);//输出矩阵
void M_delete(int**& A);//释放矩阵空间


int main()
{
	int** A1, ** A2, ** A3;
    cout << "请输入矩阵A1:" << endl;
	M_init(A1);
    cout << "请输入矩阵A2:" << endl;
    M_init(A2);
	
	A3 = new int* [ROW];//为A3申请空间
	for (int i = 0; i < ROW; i++)
		A3[i] = new int[COL];

	M_addition(A1, A2, A3);
	cout<<"输出矩阵加法结果A3:"<<endl;
	M_output(A3);

	M_subtraction(A1, A2, A3);
	cout<<"输出矩阵减法结果A3:"<<endl;
	M_output(A3);

	M_delete(A1);
	M_delete(A2);
	M_delete(A3);
	return 0;
}

void M_init(int**& A)
{
	A = new int* [ROW];//申请空间
	for (int i = 0; i < ROW; i++)
		A[i] = new int[COL];
	
	for (int i = 0; i < ROW; i++)//输入数据
		for (int j = 0; j < COL; j++)
			cin >> A[i][j];
}

void M_addition(int** A1, int** A2, int** A3)
{
	for (int i = 0; i<ROW;i++)
		for (int j = 0; j < COL; j++)
			A3[i][j] = A1[i][j] + A2[i][j];
}

void M_subtraction(int** A1, int** A2, int** A3)
{
	for (int i = 0; i < ROW; i++)
		for (int j = 0; j < COL; j++)
			A3[i][j] = A1[i][j] - A2[i][j];
}

void M_output(int** A)
{
	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < ROW; j++)
			cout << A[i][j] << " ";
		cout << endl;
	}
}

void M_delete(int**& A)
{
	for (int i = 0; i < ROW; i++)
		delete[]A[i];
	delete[]A;
}
