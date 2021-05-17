#pragma once

#ifndef __ACCOUNT_H__
#define __ACCOUNT_H__

#include "String.h"

class Account
{
private:
	int AccountID;
	int balance;
	String name;
	// char* name;

public:
	Account(int ID, int money, String nm);
	// Account(int ID, int money, char* nm);
	// Account(const Account &copy);
	// Account& operator=(const Account& ref);
	int GetID() const { return AccountID; }
	virtual void Deposit(int money) { balance += money; }
	void Withdraw(int money) { balance -= money; }
	void ShowInfo() const;
	// ~Account();
};

#endif