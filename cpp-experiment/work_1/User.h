#pragma once
#include "Basic_Library.h"
class User {
private:
	string name;//用户名
	string password;//用户密码
public:
	User(const string& n, const string& p) : name(n), password(p) {}//给定参数的构造函数
	~User() {}                                                      //析构函数
	string getName() { return name; }                               //获取用户名
	string getPassword() { return password; }                       //获取账号密码
	virtual void Register() {}										//注册
	virtual int Login() { return false; }							//登录状态
};