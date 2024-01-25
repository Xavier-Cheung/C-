#include "Basic_Library.h"
class Game {
private:
	int level;
	static vector<string> wordList;                             //����ӵĵ����б�
public:
	Game(int l = 0) { level = l; }								//Ĭ�����е����Ѷ�Ϊ1
	~Game() {}
	bool Display();                                             //�г���ʹ�õ����е���
	void setLevel(int a) { level = a; }                         //���õȼ�(�������)
	static vector<string>& getWordList() { return wordList; }   //�õ����ʱ�
	static void InitFromFile();
};
