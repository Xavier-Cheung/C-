#pragma once
#include "User.h"
#include "Basic_Library.h"

class TestBuilder :
	public User
{
private:
	int problemsNumbers;                                                                    //������
	int testBuilderLevel;                                                                   //�����Ѷ�
	static bool isLogin;                                                                    //�Ƿ��¼
	static vector<TestBuilder> testBuilderList;                                             //�ѵ�¼�ĳ������б�
public:
	TestBuilder(const string& n, const string& p, int pNum = 0, int g = 0) : User(n, p)     //��ʼ�ѶȺ���Ŀ��Ϊ0
	{
		problemsNumbers = pNum;
		testBuilderLevel = g;
	}
	~TestBuilder() {}
	static vector<TestBuilder>& getTestBuilderList() { return testBuilderList; }            //��ȡ�������б�
	void Register();                                                                        
	int Login();
	void quitLogin() { isLogin = false; }
	void addProblemsNumbers() { problemsNumbers++; }                                        //���ӳ�����
	void addTestBuilderLevel() { testBuilderLevel++; }                                      //���ӳ����Ѷ�
	void SearchTestBuilder(const string& name);                                             //ͨ������Ѱ�ҳ�����
	void SearchPlayer(const string& name);                                                  
	void SearchTesterBylevel(int level);                                                    //ͨ���ȼ�Ѱ�ҳ�����
	int getProNum() { return problemsNumbers; }                                             //�����Ŀ��
	void RankPlayersByProNum();                                                             //������������
	int getTesterLevel() { return testBuilderLevel; }                                       //��ó����ߵȼ�
	void RankPlayersByTesterLevel();                                                        //���ݳ����ߵȼ�����
	void AddWord();                                                                         //���ӵ���
	static void InitFromFile();                                                     
	void updateInfo();
};
