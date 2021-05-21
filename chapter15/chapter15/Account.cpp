#define _CRT_SECURE_NO_WARNINGS

#include "BankingCommonDecl.h"
#include "AccountException.h"
#include "Account.h"

Account::Account(int ID, int money, String nm)
	:AccountID(ID), balance(money)
{
	name = nm;
}

void Account::Withdraw(int money)
{
	if (balance < money)
		throw WithdrawException(balance);
	balance -= money;
}

void Account::ShowInfo() const
{
	std::cout << "ID : " << AccountID << std::endl;
	std::cout << "name : " << name << std::endl;
	std::cout << "balance : " << balance << std::endl;
}