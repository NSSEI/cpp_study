#pragma once

#ifndef __ACCOUNT_HANDLER_H__
#define __ACCOUNT_HANDLER_H__

#include "Account.h"

class AccountHandler
{
private:
	Account* arr[100];
	int cnt;
public:
	AccountHandler() :cnt(0) {}
	int Screen();
	void CreateAccount();
	void CreateNormalAccount();
	void CreateHighCreditAccount();
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

#endif