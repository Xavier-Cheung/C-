#include<iostream>
using namespace std;

#define ROW 4
#define COL 5

void M_init(int**& A);//��ʼ������
void M_addition(int** A1, int** A2, int** A3);//ʵ�������������
void M_subtraction(int** A1, int** A2, int** A3);//ʵ�������������
void M_output(int** A);//�������
void M_delete(int**& A);//�ͷž���ռ�


int main()
{
	int** A1, ** A2, ** A3;
    cout << "���������A1:" << endl;
	M_init(A1);
    cout << "���������A2:" << endl;
    M_init(A2);
	
	A3 = new int* [ROW];//ΪA3����ռ�
	for (int i = 0; i < ROW; i++)
		A3[i] = new int[COL];

	M_addition(A1, A2, A3);
	cout<<"�������ӷ����A3:"<<endl;
	M_output(A3);

	M_subtraction(A1, A2, A3);
	cout<<"�������������A3:"<<endl;
	M_output(A3);

	M_delete(A1);
	M_delete(A2);
	M_delete(A3);
	return 0;
}

void M_init(int**& A)
{
	A = new int* [ROW];//����ռ�
	for (int i = 0; i < ROW; i++)
		A[i] = new int[COL];
	
	for (int i = 0; i < ROW; i++)//��������
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
