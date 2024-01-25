#include "Game.h"

vector<vector<string>> Game::wordList = {};//待使用的单词列表
int Game::Display()
{
	cout << "This the " << level + 1 << "th level : "
		<< "There are " << wordList.size() << " levels totally" << endl;
	if ((unsigned int)level < wordList.size() && wordList[level].size() > 0) {
		srand((unsigned int)time(NULL));
		int pos = rand() % wordList[level].size();//随机一个level等级的单词
		cout << wordList[level][pos];
		Sleep(2000);
		cout << "\r                          \r";
		time_t timeBegin;//答题计时器
		timeBegin = time(NULL);
		string answer;
		cin >> answer;
		if (wordList[level][pos] == answer) {
			time_t timeEnd;
			timeEnd = time(NULL);
			cout << "Your answer is right. "
				<< "Time used: "
				<< timeEnd - timeBegin << endl;
			level++;
			int point;
			if (level > 7 && (timeEnd - timeBegin) < 10)//难度7以上且用时小于10s得3分
				point = 3;
			else if (level > 4 && (timeEnd - timeBegin) < 4)//难度4~6用时小于4s得2分
				point = 2;
			else//其他都只得1分
				point = 1;
			return point;
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
		abort();
	}
	unsigned int i = 0;
	while (!infile.eof())
	{
		infile >> w;
		for (; i < wordList.size(); i++){//寻找要添加的单词的难度等级【单词长度相等的行】
			if (w.size() == wordList[i][0].size())
				break;
		}
		if (i < wordList.size())//如果单词难度存在，则直接添加
			wordList[i].push_back(w);
		else {//否则创建一个新的难度
			vector <string> add;
			add.push_back(w);
			wordList.push_back(add);
		}
	}
	infile.close();
}