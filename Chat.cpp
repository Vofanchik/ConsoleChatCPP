#include "Chat.h"
#include<iostream>

void Chat::showMenu()
{
	currentUser = nullptr; //убираем указатель с выбранного юзера
	char select;
	while (!currentUser && isWork) {
		std::cout << "Выберите одно из дествий и нажмите ввод" << std::endl;
		std::cout << "Зарегестрироваться 1" << std::endl;
		std::cout << "Войти 2" << std::endl;
		std::cout << "Закрыть 3" << std::endl;
		std::cin >> select;
		// панель выбора для пользователя
		switch (select)
		{
		case '1':			
			break;
		case '2':
			break;
		case '3':
			isWork = false;
			break;
		default:
			std::cout << "Выберано некорректное дествие" << std::endl;
			break;
		}

	}
}
