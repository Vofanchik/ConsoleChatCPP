#pragma once
#include "User.h"

class Message
{
public:
	Message(const string& from, const string& to, const string& text)
		:_from(from), _to(to), _text(text) {}
	const string& GetFrom()const{ return _from;}
	const string& GetTo()const { return _to;}
	const string& GetText()const { return _text;}

	//~Message() {};

private:
	const string _from;
	const string _to;
	const string _text;
};

