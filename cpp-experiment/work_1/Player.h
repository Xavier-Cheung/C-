#pragma once
#include "User.h"
#include "Basic_Library.h"

class Player : 
    public User 
{
private:
	int playerLevel;                                                                        //��ҵȼ�
	int experience;                                                                         //��Ҿ���
	int gainedGrades;                                                                       //��һ�ȡ�ķ���
	static bool isLogin;                                                                    //�Ƿ��¼
	static vector<Player> playerList;                                                       //�ѵ�¼������б�
public:
	Player(const string& n, const string& p, int e = 0, int l = 0, int g = 0) : User(n, p)  //��Ϊ���û����򶼳�ʼ��Ϊ0
	{
		playerLevel = l;
		experience = e;
		gainedGrades = g;
	}
	~Player() {}
	static vector<Player>& getList() { return playerList; }                                 //�������б�
	void Register();                                                                        //ע��
	int Login();                                                                            //��¼
	int getGrades() { return gainedGrades; }                                                //��ȡ����
	int getExperience() { return experience; }                                              //��ȡ����
	int getPlayerLvel() { return playerLevel; }                                             //��õȼ�
	void quitLogin() { isLogin = false; }                                                   //�˳���¼
	void addLevel() { playerLevel++; }                                                      //����
	void addExperience() { experience++; }                                                  //���Ӿ���
	void addGainedGrades() { gainedGrades++; }                                              //���ӷ���
	void SearchPlayer(string& name);                                                        //Ѱ����ң�����id��
	void SearchTestBuilder(string& name);                                                   //Ѱ�ҳ�����
	void SearchPlayerBylevel(int level);                                                    //���ݵȼ�Ѱ�����
	void RankPlayersByGrades();                                                             //���ݷ�������
	void RankPlayersByExperience();                                                         //������߼�������
	void RankPlayersByBestLevel();                                                          //���ݵȼ�����
	void updateInfo();                                                                      //������Ϣ
	static void InitFromFile();                                                             
};