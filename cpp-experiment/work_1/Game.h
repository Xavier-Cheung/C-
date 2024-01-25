#include "Basic_Library.h"
class Game {
private:
	int level;
	static vector<string> wordList;                             //被添加的单词列表
public:
	Game(int l = 0) { level = l; }								//默认所有单词难度为1
	~Game() {}
	bool Display();                                             //列出待使用的所有单词
	void setLevel(int a) { level = a; }                         //设置等级(单词序号)
	static vector<string>& getWordList() { return wordList; }   //得到单词表
	static void InitFromFile();
};
