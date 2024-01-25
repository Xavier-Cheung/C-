#pragma once
#include "User.h"
#include "Basic_Library.h"

class Player : 
    public User 
{
private:
	int playerLevel;                                                                        //玩家等级
	int experience;                                                                         //玩家经验
	int gainedGrades;                                                                       //玩家获取的分数
	static bool isLogin;                                                                    //是否登录
	static vector<Player> playerList;                                                       //已登录的玩家列表
public:
	Player(const string& n, const string& p, int e = 0, int l = 0, int g = 0) : User(n, p)  //若为新用户，则都初始化为0
	{
		playerLevel = l;
		experience = e;
		gainedGrades = g;
	}
	~Player() {}
	static vector<Player>& getList() { return playerList; }                                 //获得玩家列表
	void Register();                                                                        //注册
	int Login();                                                                            //登录
	int getGrades() { return gainedGrades; }                                                //获取分数
	int getExperience() { return experience; }                                              //获取经验
	int getPlayerLvel() { return playerLevel; }                                             //获得等级
	void quitLogin() { isLogin = false; }                                                   //退出登录
	void addLevel() { playerLevel++; }                                                      //升级
	void addExperience() { experience++; }                                                  //增加经验
	void addGainedGrades() { gainedGrades++; }                                              //增加分数
	void SearchPlayer(string& name);                                                        //寻找玩家（根据id）
	void SearchTestBuilder(string& name);                                                   //寻找出题者
	void SearchPlayerBylevel(int level);                                                    //根据等级寻找玩家
	void RankPlayersByGrades();                                                             //根据分数排名
	void RankPlayersByExperience();                                                         //根据最高级别排名
	void RankPlayersByBestLevel();                                                          //根据等级排名
	void updateInfo();                                                                      //更新信息
	static void InitFromFile();                                                             
};