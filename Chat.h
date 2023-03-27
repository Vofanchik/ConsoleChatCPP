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

public:
	
	bool isChatWork()const {return isWork;}
	void run() { isWork = true; }
	void showMenu();
	void showUserMenu();
	void signUp();
	void showUsers();

};

