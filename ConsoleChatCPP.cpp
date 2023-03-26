#include <iostream>
#include "Chat.h"

int main()
{
	setlocale(LC_ALL, "Russian");
	Chat chat;
	chat.run(); // меняем переменную isWork на true

	while (chat.isChatWork()) // цикл работы чата
	{
		chat.showMenu();
	}
    return 0;
}

