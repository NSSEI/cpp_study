#pragma once

#ifndef __ACCOUNT_HANDLER_H__
#define __ACCOUNT_HANDLER_H__

#include "Account.h"
#include "BoundCheckArray.h"

class AccountHandler
{
private:
	BoundCheckArray<Account*> arr;
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
	~AccountHandler();
};

#endif