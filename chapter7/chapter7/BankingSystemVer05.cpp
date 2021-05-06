#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>

class Account
{
private:
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
	Account(const Account &copy)
		:AccountID(copy.AccountID), balance(copy.balance)
	{
		name = new char[strlen(copy.name) + 1];
		strcpy(name, copy.name);
	}
	int GetID() const { return AccountID; }
	void Deposit(int money) { balance += money; }
	void Withdraw(int money) { balance -= money; }
	void ShowInfo() const
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

class AccountHandler
{
private:
	Account* arr[100];
	int cnt;
public:
	AccountHandler() :cnt(0) {}
	int Screen();
	void CreateAccount();
	void Deposit();
	void Withdraw();
	void AccountInfo();
	~AccountHandler()
	{
		for (int i = cnt - 1; i >= 0; i--)
		{
			delete arr[i];
		}
	}
};



int main()
{
	AccountHandler sc;
	int num;

	while (true)
	{
		num = sc.Screen();
		if (num == 5) { break; }
	}

	return 0;
}

int AccountHandler::Screen()
{
	int val;

	std::cout << "----Menu-----" << std::endl;
	std::cout << "1. 계좌개설" << std::endl;
	std::cout << "2. 입 금" << std::endl;
	std::cout << "3. 출 금" << std::endl;
	std::cout << "4. 계좌정보 전체 출력" << std::endl;
	std::cout << "5. 프로그램 종료" << std::endl;
	std::cout << "선택 : ";
	std::cin >> val;
	std::cout << std::endl;

	switch (val)
	{
	case 1:
		AccountHandler::CreateAccount();
		break;
	case 2:
		AccountHandler::Deposit();
		break;
	case 3:
		AccountHandler::Withdraw();
		break;
	case 4:
		AccountHandler::AccountInfo();
		break;
	case 5:
		std::cout << "Exit" << std::endl;
		break;
	default:
		std::cout << "Error. Choose again." << std::endl;
	}

	return val;
}

void AccountHandler::CreateAccount()
{
	int AccountID, amount;
	char name[10];

	std::cout << "[계좌개설]" << std::endl;
	std::cout << "Account ID : ";
	std::cin >> AccountID;
	std::cout << "Name : ";
	std::cin >> name;
	std::cout << "Amount : ";
	std::cin >> amount;
	std::cout << std::endl;

	arr[cnt++] = new Account(AccountID, amount, name);
}

void AccountHandler::Deposit()
{
	int AccountID, amount;

	std::cout << "[입 금]" << std::endl;
	std::cout << "Account ID : ";
	std::cin >> AccountID;
	std::cout << "Amount : ";
	std::cin >> amount;
	std::cout << "Complete" << std::endl;
	std::cout << std::endl;

	for (int i = cnt - 1; i >= 0; i--)
	{
		if (arr[i]->GetID() == AccountID)
		{
			arr[i]->Deposit(amount);
		}
	}
}

void AccountHandler::Withdraw()
{
	int AccountID, amount;

	std::cout << "[출 금]" << std::endl;
	std::cout << "Account ID : ";
	std::cin >> AccountID;
	std::cout << "Amount : ";
	std::cin >> amount;
	std::cout << "Complete" << std::endl;
	std::cout << std::endl;

	for (int i = cnt - 1; i >= 0; i--)
	{
		if (arr[i]->GetID() == AccountID)
		{
			arr[i]->Withdraw(amount);
		}
	}
}

void AccountHandler::AccountInfo()
{
	for (int i = cnt - 1; i >= 0; i--)
	{
		arr[i]->ShowInfo();
		std::cout << std::endl;
	}
}