#include "BankingCommonDecl.h"
#include "AccountHandler.h"
#include "Account.h"
#include "NormalAccount.h"
#include "HighCreditAccount.h"


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
	int kind;

	std::cout << "[계좌 종류 선택]" << std::endl;
	std::cout << "1. 보통예금계좌  2. 신용신뢰계좌" << std::endl;
	std::cout << "선택 : ";
	std::cin >> kind;

	if (kind == 1)
		CreateNormalAccount();
	else
		CreateHighCreditAccount();
}

void AccountHandler::CreateNormalAccount()
{
	int AccountID, amount, interest;
	char name[10];

	std::cout << "[보통예금계좌 개설]" << std::endl;
	std::cout << "Account ID : ";
	std::cin >> AccountID;
	std::cout << "Name : ";
	std::cin >> name;
	std::cout << "Amount : ";
	std::cin >> amount;
	std::cout << "Interest : ";
	std::cin >> interest;
	std::cout << std::endl;

	arr[cnt++] = new NormalAccount(AccountID, amount, name, interest);
}

void AccountHandler::CreateHighCreditAccount()
{
	int AccountID, amount, interest, grade;
	char name[10];

	std::cout << "[신용신뢰계좌 개설]" << std::endl;
	std::cout << "Account ID : ";
	std::cin >> AccountID;
	std::cout << "Name : ";
	std::cin >> name;
	std::cout << "Amount : ";
	std::cin >> amount;
	std::cout << "Interest : ";
	std::cin >> interest;
	std::cout << "신용등급 : ";
	std::cin >> grade;
	std::cout << std::endl;

	switch (grade)
	{
	case 1:
		arr[cnt++] = new HighCreditAccount(AccountID, amount, name, interest, GRADE_A);
		break;
	case 2:
		arr[cnt++] = new HighCreditAccount(AccountID, amount, name, interest, GRADE_B);
		break;
	case 3:
		arr[cnt++] = new HighCreditAccount(AccountID, amount, name, interest, GRADE_C);
		break;
	}
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

AccountHandler::~AccountHandler()
{
	for (int i = cnt - 1; i >= 0; i--)
	{
		delete arr[i];
	}
}