#include "Chat.h"
#include "User.h"
#include "Message.h"
#include<iostream>
using namespace std;

User* Chat::ReturnUserByLogin(const string& login) {
	for (auto& user : users) {
		if (login == user.GetUserLogin())
			return &user;
	}

	return nullptr;
}

void Chat::showMenu()
{

	currentUser = nullptr; //убираем указатель с выбранного юзера
	char select;
	while (!currentUser && isWork) {
		cout << "Выберите одно из действий и нажмите ввод" << std::endl;
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
			signIn();
			break;
		case '3':
			isWork = false;
			break;
		default:
			cout << "Выбрано некорректное действие" << std::endl;
			break;
		}

	}
}

void Chat::showUserMenu() {
	char select;
	std::cout << "Привет, " << currentUser->GetUserLogin() << std::endl;
	while (currentUser) {
		cout << "Выберите одно из действий и нажмите ввод" << std::endl;
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
			addMessage();
			break;
		case '3':
			showUsers();
			break;
		case'4':
			showChat();
			break;
		default:
			cout << "Выбрано некорректное действие" << std::endl;
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

void Chat::signIn() {
	string login, password;
	cout << "Логин: ";
	cin >> login;
	cout << "Пароль:";
	cin >> password;

	for (int i = 0; i < users.size(); i++) {
		if ((users[i].GetUserLogin() == login) && (users[i].GetUserPassword() == password)) {
			currentUser = &users[i];
				showUserMenu();
		}
	}
	cout << "Логин или пароль не верен";
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

void Chat::addMessage() {
	string to, text;
	cout << "Кому (всем или имя):";
	cin >> to;
	cout << "Текст:";
	cin >> text;
	//cin.ignore();
	//getline(cin, text);

	if (!(to == "all" || ReturnUserByLogin(to)))//если не удалось найти получателя по имени
	{
		cout << "Error send message:cannt find" << to << endl;
			return;
	}
	if (to=="all")
		messages.push_back(Message{ currentUser->GetUserLogin(),"all",text });
	else
		messages.push_back(Message{ currentUser->GetUserLogin(),ReturnUserByLogin(to)->GetUserLogin(),text });
}
void Chat::showChat()
{
	string from;
	string to;
	cout << "---Письма---" << endl;
	for (auto& mess : messages)
	{//показывает сообщения от текущего пользователя,для него,для всех
		if (currentUser->GetUserLogin() == mess.GetFrom() || currentUser->GetUserLogin() == mess.GetTo() || mess.GetTo() == "all")
		{// подменяем для себя имя на me
			from = (currentUser->GetUserLogin() == mess.GetFrom()) ? "me" : mess.GetFrom();
			if (mess.GetTo() == "all")
			{
				to = "(all)";
			}
			else
			{
				to = (currentUser->GetUserLogin() == mess.GetTo()) ? "me" : mess.GetTo();
			}
			cout << "Сообщение от: " << from <<endl<< "Kому: " << to << endl;
			cout << "Текст: " << mess.GetText() << endl;
		}
		cout << "-------------" << endl;
	}
}

  