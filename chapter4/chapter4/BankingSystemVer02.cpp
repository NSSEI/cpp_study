#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>

int Screen();
void CreateAccount();
void Deposit();
void Withdraw();
void AccountInfo();

class Account
{
	int AccountID;
	int balance;
	char* name;
public:
	Account(int ID, int money, char* nm)
		:AccountID(ID), balance(money)
	{
		name = new char[strlen(nm) + 1];
		strcpy(name, nm);
	}
	int GetID() { return AccountID; }
	void Deposit(int money) { balance += money; }
	void Withdraw(int money){ balance -= money; }
	void ShowInfo()
	{
		std::cout << "ID : " << AccountID << std::endl;
		std::cout << "name : " << name << std::endl;
		std::cout << "balance : " << balance << std::endl;
	}
	~Account()
	{
		delete[] name;
	}
};

Account* arr[100];
int cnt = 1;

int main()
{
	int val;
	while (true)
	{
		val = Screen();
		if (val == 5) { break; }
	}

	return 0;
}

int Screen()
{
	int val;

	std::cout << "----Menu-----" << std::endl;
	std::cout << "1. ���°���" << std::endl;
	std::cout << "2. �� ��" << std::endl;
	std::cout << "3. �� ��" << std::endl;
	std::cout << "4. �������� ��ü ���" << std::endl;
	std::cout << "5. ���α׷� ����" << std::endl;
	std::cout << "���� : ";
	std::cin >> val;
	std::cout << std::endl;

	switch (val)
	{
	case 1:
		CreateAccount();
		break;
	case 2:
		Deposit();
		break;
	case 3:
		Withdraw();
		break;
	case 4:
		AccountInfo();
		break;
	case 5:
		std::cout << "Exit" << std::endl;
		break;
	default:
		std::cout << "Error. Choose again." << std::endl;
		break;
	}

	return val;
}

void CreateAccount()
{
	int AccountID, amount;
	char name[10];

	std::cout << "[���°���]" << std::endl;
	std::cout << "Account ID : ";
	std::cin >> AccountID;
	std::cout << "Name : ";
	std::cin >> name;
	std::cout << "Amount : ";
	std::cin >> amount;
	std::cout << std::endl;

	arr[cnt++] = new Account(AccountID, amount, name);
}

void Deposit()
{
	int AccountID, amount;

	std::cout << "[�� ��]" << std::endl;
	std::cout << "Account ID : ";
	std::cin >> AccountID;
	std::cout << "Amount : ";
	std::cin >> amount;
	std::cout << "Complete" << std::endl;
	std::cout << std::endl;

	for (int i = cnt - 1; i != 0; i--)
	{
		if (arr[i]->GetID() == AccountID)
		{
			arr[i]->Deposit(amount);
		}
	}
}

void Withdraw()
{
	int AccountID, amount;

	std::cout << "[�� ��]" << std::endl;
	std::cout << "Account ID : ";
	std::cin >> AccountID;
	std::cout << "Amount : ";
	std::cin >> amount;
	std::cout << "Complete" << std::endl;
	std::cout << std::endl;

	for (int i = cnt - 1; i != 0; i--)
	{
		if (arr[i]->GetID() == AccountID)
		{
			arr[i]->Withdraw(amount);
		}
	}
}

void AccountInfo()
{
	for (int i = cnt - 1; i != 0; i--)
	{
		arr[i]->ShowInfo();
		std::cout << std::endl;
	}
}