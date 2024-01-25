#include "Game.h"

vector<string> Game::wordList = {};//��ʹ�õĵ��ʱ�
bool Game::Display()//�������ط���true��������ͨ�ط���false
{
	cout << "This is the " << level + 1 << "th level : "
		<< "There are " << wordList.size() << " levels totally" << endl;
	if ((unsigned)level < wordList.size()) {//��δ�������д�
		cout << wordList[level];
		Sleep(2000);//sleepʵ�ֵ��ʵı���ʱ��
		cout << "\r                   \r";//�ûس�����������ո��ٻس�ʵ�ֵ��ʲ���������ͬһ�н�������
		string answer;
		cin >> answer;
		if (wordList[level] == answer) {
			cout << "Your answer is right." << endl;
			level++;
			return true;
		}
		else {
			cout << "Your answer is wrong." << endl;
			return false;
		}
	}
	else {
		cout << "Congratulations! You have reached the last level." << endl;
		return false;
	}
}
void Game::InitFromFile()
{
	string w;
	ifstream infile("wordList.csv");
	if (!infile) {
		cout << "File wordList.csv open failed!" << endl;
		abort();//��ִֹ��
	}
	while (!infile.eof())//���ļ�������δ����
	{
		getline(infile, w);//���ж�ȡ
		wordList.push_back(w);
	}
	infile.close();
}