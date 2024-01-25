#pragma once
#include "User.h"
#include "Basic_Library.h"

class TestBuilder :
	public User
{
private:
	int problemsNumbers;                                                                    //出题数
	int testBuilderLevel;                                                                   //出题难度
	static bool isLogin;                                                                    //是否登录
	static vector<TestBuilder> testBuilderList;                                             //已登录的出题者列表
public:
	TestBuilder(const string& n, const string& p, int pNum = 0, int g = 0) : User(n, p)     //初始难度和题目数为0
	{
		problemsNumbers = pNum;
		testBuilderLevel = g;
	}
	~TestBuilder() {}
	static vector<TestBuilder>& getTestBuilderList() { return testBuilderList; }            //获取出题者列表
	void Register();                                                                        
	int Login();
	void quitLogin() { isLogin = false; }
	void addProblemsNumbers() { problemsNumbers++; }                                        //增加出题数
	void addTestBuilderLevel() { testBuilderLevel++; }                                      //增加出题难度
	void SearchTestBuilder(const string& name);                                             //通过名字寻找出题者
	void SearchPlayer(const string& name);                                                  
	void SearchTesterBylevel(int level);                                                    //通过等级寻找出题者
	int getProNum() { return problemsNumbers; }                                             //获得题目数
	void RankPlayersByProNum();                                                             //根据题数排名
	int getTesterLevel() { return testBuilderLevel; }                                       //获得出题者等级
	void RankPlayersByTesterLevel();                                                        //根据出题者等级排名
	void AddWord();                                                                         //增加单词
	static void InitFromFile();                                                     
	void updateInfo();
};
