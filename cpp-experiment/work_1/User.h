#pragma once
#include "Basic_Library.h"
class User {
private:
	string name;//�û���
	string password;//�û�����
public:
	User(const string& n, const string& p) : name(n), password(p) {}//���������Ĺ��캯��
	~User() {}                                                      //��������
	string getName() { return name; }                               //��ȡ�û���
	string getPassword() { return password; }                       //��ȡ�˺�����
	virtual void Register() {}										//ע��
	virtual int Login() { return false; }							//��¼״̬
};