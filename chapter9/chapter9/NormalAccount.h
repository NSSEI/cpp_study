#pragma once

#ifndef __NORMAL_H__
#define __NORMAL_H__

#include "Account.h"

class NormalAccount : public Account
{
private:
	int interest;
public:
	NormalAccount(int ID, int money, char* nm, int inter)
		:Account(ID, money, nm), interest(inter) {}
	virtual void Deposit(int money)
	{
		Account::Deposit(money);
		Account::Deposit(money * interest / 100);
	}
};
#endif