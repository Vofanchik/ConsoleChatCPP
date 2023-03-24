#pragma once
#include <vector>
#include "Message.h"
#include "User.h"

class Chat
{
	bool isWork = false;

	std::vector<User> users;
	std::vector<Message> messages;
	User* currentUser = nullptr;

public:
	
	bool isChatWork()const {return isWork;}
	void run() { isWork = true; }
	void showMenu();

};

