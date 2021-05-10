#pragma once

#ifndef __ACCOUNT_H__
#define __ACCOUNT_H__

class Account
{
private:
	int AccountID;
	int balance;
	char* name;

public:
	Account(int ID, int money, char* nm);
	Account(const Account &copy);
	int GetID() const { return AccountID; }
	virtual void Deposit(int money) { balance += money; }
	void Withdraw(int money) { balance -= money; }
	void ShowInfo() const;
	~Account();
};

#endif