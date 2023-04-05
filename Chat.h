#pragma once
#include <vector>
#include "Message.h"
#include "User.h"
#include <exception>
using namespace std;

class UserLoginExp: public exception
{
public:
	virtual const char* what() const noexcept override
	{
		return "Ошибка: Такой пользователь уже зарегистрирован! \n";
	}
};

class UserSearchExp : public exception
{
public:
	virtual const char* what() const noexcept override
	{
		return "Ошибка: Такой пользователь отсутствует! \n";
	}
};

class UserloginExp : public exception
{
public:
	virtual const char* what() const noexcept override
	{
		return "Ошибка: Логин или пароль не верны! \n";
	}
};

class Chat
{
	bool isWork = false;

	vector<User> users;

	vector<Message> messages;
	User* currentUser = nullptr;
	User* acceptorUser = nullptr;

public:
	void Scope();
	bool isChatWork()const {return isWork;}
	void run() { isWork = true; }
	User* ReturnUserByLogin(const string& login);
	void showMenu();
	void showUserMenu();
	void signUp();
	void signIn();
	void showUsers();
	void addMessage();
	void showChat();
};

