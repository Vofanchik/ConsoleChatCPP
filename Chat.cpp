#include "Chat.h"
#include<iostream>

void Chat::showMenu()
{
	currentUser = nullptr; //������� ��������� � ���������� �����
	char select;
	while (!currentUser && isWork) {
		std::cout << "�������� ���� �� ������� � ������� ����" << std::endl;
		std::cout << "������������������ 1" << std::endl;
		std::cout << "����� 2" << std::endl;
		std::cout << "������� 3" << std::endl;
		std::cin >> select;
		// ������ ������ ��� ������������
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
			std::cout << "�������� ������������ �������" << std::endl;
			break;
		}

	}
}
