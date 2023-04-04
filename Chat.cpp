#include "Chat.h"
#include "User.h"
#include "Message.h"
#include<iostream>
#include<string>
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
	// объявляю функцию которая добавляет парочку аккаунтов для теста 
	Scope();

	currentUser = nullptr; //убираем указатель с выбранного юзера
	char select;
	while (!currentUser && isWork) {
		cout << "Выберите одно из действий и нажмите ввод" << std::endl;
		cout << "Зарегистрироваться 1" << std::endl; // зарегистрироваться
		cout << "Войти 2" << std::endl;
		cout << "Закрыть 3" << std::endl;
		cin >> select;
		// панель выбора для пользователя
	
		switch (select)
		{
		case '1':
			// проверка на наличие уже зарегистрированного пользователя ранее (код написан как исключение)
			try {
				signUp();
			}catch (const string ex) {
				cout << "Такой пользователь уже зарегистрирован! (введите новый логин и пароль)" << endl;
			}
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
			cout << "Список пользователей: " << endl;
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
	// функция для теста (зареганные пользователи)
	void Chat::Scope() {
		// для теста добавил в вектор users пользователей (типа они были зарегистрированны ранее)
	// после сверки и соответствия логина и пароля - показ меню для написания сообщения
		users.push_back({ "Denis", "1" });
		users.push_back({ "Olya", "2" });
		users.push_back({ "Vladimir", "3" });
	}
void Chat::signUp() {
	string login, password;
	cout << "Логин: ";
	cin >> login;
	cout << "Пароль:";
	cin >> password;


for (int i = 0; i < users.size(); i++) {
		if ((users[i].GetUserLogin() == login) && (users[i].GetUserPassword() == password)) {
			// throw ловит исключение по уже зарегистрированному пользователю (для примера выше добавлен код)
			// если нет такого в базе то показ меню для написания сообщения в противном случае - пользователь зарегистрирован ранее
			throw login;
			showUserMenu();
		}
	}
	User user = User(login, password);
	users.push_back(user);
	currentUser = &user;
	showUserMenu();
}
// войти в текущий аккаунт
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
	cout << "Сообщение отправлено!"<< endl;
	cin.ignore();
	getline(cin, text);



	if (!(to == "all" || ReturnUserByLogin(to)))//если не удалось найти получателя по имени
	{
		cout << "Error send message:cannot find" << to << endl;
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