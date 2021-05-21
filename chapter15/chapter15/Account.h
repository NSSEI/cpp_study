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

public:
	Account(int ID, int money, String nm);
	int GetID() const { return AccountID; }
	virtual void Deposit(int money) { balance += money; }
	void Withdraw(int money);
	void ShowInfo() const;
};

#endif