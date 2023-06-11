#include <iostream>
#include "Chat.h"
// #include <windows.h>
int main()
{
// 	SetConsoleCP(65001);
// 	SetConsoleOutputCP(65001);
	setlocale(LC_ALL, "Russian"); //привет
	Chat chat;
	chat.run(); // меняем переменную isWork на true

	while (chat.isChatWork()) // цикл работы чата
	{
		chat.showMenu();
	}
    return 0;
}

