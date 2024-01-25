#include "Game.h"

vector<string> Game::wordList = {};//待使用的单词表
bool Game::Display()//正常闯关返回true，答错或者通关返回false
{
	cout << "This is the " << level + 1 << "th level : "
		<< "There are " << wordList.size() << " levels totally" << endl;
	if ((unsigned)level < wordList.size()) {//还未猜完所有词
		cout << wordList[level];
		Sleep(2000);//sleep实现单词的保留时长
		cout << "\r                   \r";//用回车和重新输出空格再回车实现单词擦除，并在同一行进行输入
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
		abort();//终止执行
	}
	while (!infile.eof())//当文件输入流未结束
	{
		getline(infile, w);//逐行读取
		wordList.push_back(w);
	}
	infile.close();
}