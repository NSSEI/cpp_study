#pragma once

#ifndef __HIGHCREDIT_ACCOUNT_H__
#define __HIGHCREDIT_ACCOUNT_H__

#include "NormalAccount.h"

class HighCreditAccount :public NormalAccount
{
private:
	int grade;
public:
	HighCreditAccount(int ID, int money, char* nm, int inter, int gr)
		: NormalAccount(ID, money, nm, inter), grade(gr) {}
	virtual void Deposit(int money)
	{
		NormalAccount::Deposit(money);
		Account::Deposit(money * grade / 100);
	}
};

#endif // !__HIGHCREDIT_ACCOUNT_H__