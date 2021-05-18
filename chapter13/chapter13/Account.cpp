#define _CRT_SECURE_NO_WARNINGS

#include "BankingCommonDecl.h"
#include "Account.h"

Account::Account(int ID, int money, String nm)
	:AccountID(ID), balance(money)
{
	// name = new char[strlen(nm) + 1];
	// strcpy(name, nm);
	name = nm;
}

/*
Account::Account(const Account &copy)
	:AccountID(copy.AccountID), balance(copy.balance)
{
	name = new char[strlen(copy.name) + 1];
	strcpy(name, copy.name);
}

Account& Account::operator=(const Account& ref)
{
	AccountID = ref.AccountID;
	balance = ref.balance;

	delete[] name;
	name = new char[strlen(ref.name) + 1];
	strcpy(name, ref.name);
	return *this;
}
*/

void Account::ShowInfo() const
{
	std::cout << "ID : " << AccountID << std::endl;
	std::cout << "name : " << name << std::endl;
	std::cout << "balance : " << balance << std::endl;
}

// Account::~Account() { delete[] name; }

