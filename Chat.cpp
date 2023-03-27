#include "Chat.h"
#include<iostream>
using namespace std;

void Chat::showMenu()
{

	currentUser = nullptr; //убираем указатель с выбранного юзера
	char select;
	while (!currentUser && isWork) {
		cout << "Выберите одно из дествий и нажмите ввод" << std::endl;
		cout << "Зарегестрироваться 1" << std::endl;
		cout << "Войти 2" << std::endl;
		cout << "Закрыть 3" << std::endl;
		cin >> select;
		// панель выбора для пользователя
		switch (select)
		{
		case '1':
			signUp();
			break;
		case '2':
			break;
		case '3':
			isWork = false;
			break;
		default:
			cout << "Выбрано некорректное дествие" << std::endl;
			break;
		}

	}
}

void Chat::showUserMenu() {
	char select;
	std::cout << "Привет, " << currentUser->GetUserLogin() << std::endl;
	while (currentUser) {
		cout << "Выберите одно из дествий и нажмите ввод" << std::endl;
		cout << "Выйти из аккаунта 1" << std::endl;
		cout << "Отправить письмо 2" << std::endl;
		cout << "Посмотреть список пользователей 3" << std::endl;
		cout << "Посмотреть письма 4" << std::endl;

		cin >> select;
		switch (select) {
		case '1':
			currentUser = nullptr;
			break;
		case '2':
			break;
		case '3':
			showUsers();
			break;
		case'4':
			break;
		default:
			cout << "Выбрано некорректное дествие" << std::endl;
			break;
		}
	}
}


void Chat::signUp() {
	string login, password;
	cout << "Логин: ";
	cin >> login;
	cout << "Пароль:";
	cin >> password;
	

	User user = User(login, password);
	users.push_back(user);
	currentUser = &user;
	showUserMenu();
}

void Chat::showUsers() {
	cout << "-Пользователи-" << endl;
	for (int i = 0; i < users.size(); i++ ) {
		cout << users[i].GetUserLogin();
		if (currentUser->GetUserLogin() == users[i].GetUserLogin())
			cout << "*";
		cout << endl;

	}
	cout << "---------" << endl;
}