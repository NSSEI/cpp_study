#pragma once

#ifndef __NORMAL_ACCOUNT_H__
#define __NORMAL_ACCOUNT_H__

#include "Account.h"
#include "String.h"

class NormalAccount : public Account
{
private:
	int interest;
public:
	NormalAccount(int ID, int money, String nm, int inter)
		:Account(ID, money, nm), interest(inter) {}
	virtual void Deposit(int money)
	{
		Account::Deposit(money);
		Account::Deposit(money * interest / 100);
	}
};
#endif