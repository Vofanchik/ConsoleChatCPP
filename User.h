#pragma once
#include <string>
using namespace std;

class User
{
public:
	User(const string& login, const string& password)
		:login_(login), password_(password) {}

	const string& GetUserLogin(){
		return login_;
	}
	const string& GetUserPassword(){
		return password_;
	}
	//Hello

	//~User() {};

private:
	const string login_;
	const string password_;

};

