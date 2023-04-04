#pragma once
#include <vector>
#include "Message.h"
#include "User.h"
using namespace std;

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

