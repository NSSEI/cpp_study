#include "BankingCommonDecl.h"
#include "AccountHandler.h"
#include "Account.h"
#include "NormalAccount.h"
#include "HighCreditAccount.h"


int AccountHandler::Screen()
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

	std::cout << "[���� ���� ����]" << std::endl;
	std::cout << "1. ���뿹�ݰ���  2. �ſ�ŷڰ���" << std::endl;
	std::cout << "���� : ";
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

	std::cout << "[���뿹�ݰ��� ����]" << std::endl;
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

	std::cout << "[�ſ�ŷڰ��� ����]" << std::endl;
	std::cout << "Account ID : ";
	std::cin >> AccountID;
	std::cout << "Name : ";
	std::cin >> name;
	std::cout << "Amount : ";
	std::cin >> amount;
	std::cout << "Interest : ";
	std::cin >> interest;
	std::cout << "�ſ��� : ";
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

	std::cout << "[�� ��]" << std::endl;
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

	std::cout << "[�� ��]" << std::endl;
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