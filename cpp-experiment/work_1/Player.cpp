#include "Player.h"
#include "TestBuilder.h"
#include "split.h"

bool Player::isLogin = 0;
vector<Player> Player::playerList = {};//待使用的玩家列表

void Player::Register()
{
	for (int i = 0; i < (int)playerList.size(); i++) {//遍历玩家列表，名字相同则注册过
		if(playerList[i].getName()==this->getName()) {
			cout << "The Player-Name has been registered. Register failed!" << endl;
			return;
		}
	}
//ofstream 内存->硬盘
	ofstream outfile("playerList.csv", ios::app);//没文件就生成，有文件就在后面追加
	if (!outfile) {
		cout << "File playerList.csv open failed!" << endl;
		abort();//终止程序不清除对象
	}
	outfile << this->getName() << "," << this->getPassword() << "," << this->playerLevel << "," << this->experience << "," << this->gainedGrades << "    " << endl;
	outfile.close();
	playerList.push_back(*this);
	cout << "Player successfully registers!" << endl;
}

int Player::Login()//返回player的序号
{
	if (isLogin)
		return -2;
	for (int i = 0; i < (int)playerList.size(); i++)
		if (playerList[i].getName() == this->getName() && playerList[i].getPassword() == this->getPassword()) {
			cout << "Player successfully logins!" << endl;
			isLogin = true;
			return i;
		}
	cout << "Player-login failed!" << endl;
	return -1;
}

void Player::SearchPlayer(string& name)
{
	vector<Player> v = Player::getList();
	for (unsigned int i = 0; i < v.size(); i++)
		if (v[i].getName() == name) {
			cout << "It is the " << i + 1 << "th player" << endl;
			return;
		}
	cout << "It is not exited in the playerList." << endl;
}

void Player::SearchTestBuilder(string& name)
{
	vector<TestBuilder> v = TestBuilder::getTestBuilderList();
	for (unsigned int i = 0; i < v.size(); i++)
		if (v[i].getName() == name) {
			cout << "It is the " << i + 1 << "th tester" << endl;
			return;
		}
	cout << "It is not exited in the testBuilderList." << endl;
}

void Player::SearchPlayerBylevel(int level)
{
	vector<Player> v = Player::getList();
	for (unsigned int i = 0; i < v.size(); i++)
		if (v[i].getPlayerLvel() >= level) {
			cout << "The " << i + 1 << "th player: " << v[i].getName() << endl;
		}
}

bool sortByGrades(Player a, Player b)//比较器
{
	return a.getGrades() > b.getGrades();
}
void Player::RankPlayersByGrades()
{
	vector<Player> v = Player::getList();
	sort(v.begin(), v.end(), sortByGrades);
	for (unsigned int i = 0; i < v.size(); i++)
		cout << i + 1 << "th   " << v[i].getName() << " with gainedGrades is: " << v[i].getGrades() << endl;
}

bool sortByExperience(Player a, Player b)
{
	return a.getExperience() > b.getExperience();
}
void Player::RankPlayersByExperience()
{
	vector<Player> v = Player::getList();
	sort(v.begin(), v.end(), sortByGrades);
	for (unsigned int i = 0; i < v.size(); i++)
		cout << i + 1 << "th   " << v[i].getName() << " with experience is: " << v[i].getExperience() << endl;
}

bool sortByBestLevel(Player a, Player b)
{
	return a.getPlayerLvel() > b.getPlayerLvel();
}
void Player::RankPlayersByBestLevel()
{
	vector<Player> v = Player::getList();
	sort(v.begin(), v.end(), sortByBestLevel);
	for (unsigned int i = 0; i < v.size(); i++)
		cout << i + 1 << "th   " << v[i].getName() << " with best level is: " << v[i].getPlayerLvel() << endl;
}

void Player::InitFromFile()//从已有列表中将player放入待使用列表中
{
	string line;
	vector<string> v;
	ifstream infile("playerList.csv");
	if (!infile) {
		cout << "File playerList.csv open failed!" << endl;
		abort();
	}
	getline(infile, line);
	while (!infile.eof())
	{
		getline(infile, line);
		if(line == "")
			break;
		v = split(line, ",");
		Player player(v[0], v[1], atoi(v[2].c_str()), atoi(v[3].c_str()), atoi(v[4].c_str()));//返回的是const char*
		playerList.push_back(player);
	}
	infile.close();
}

void Player::updateInfo()//更新playerList.csv
{
	fstream outfile("playerList.csv", ios::out | ios::in);
	if (!outfile) {
		cout << "File playerList.csv open failed!" << endl;
		abort();
	}
	string line;
	vector<string> v;
	outfile.seekp(0);
	getline(outfile, line);
	streamoff cur_tmp = outfile.tellg();//找到现在文件输出的偏移量位置
	while (!outfile.eof())
	{
		getline(outfile, line);
		v = split(line, ",");
		if (strcmp(this->getName().c_str(), v[0].c_str()) == 0) {//playername相同则从该行开头开始更新覆盖数据
			outfile.seekp(cur_tmp);
			outfile << this->getName() << "," << this->getPassword() << "," << this->playerLevel << "," << this->experience << "," << this->gainedGrades;
			break;
		}
		cur_tmp = outfile.tellg();
	}
	outfile.close();
}
