#pragma once

#ifndef __ACCOUNT_EXCEPTION_H__
#define __ACCOUNT_EXCEPTION_H__

#include "BankingCommonDecl.h"

class AccountException
{
public:
	virtual void ShowException() = 0;
};

class MinusInputException : public AccountException
{
private:
	int money;
public:
	MinusInputException(int input) :money(input) {}
	void ShowException()
	{
		std::cout << "0보다 작은 값이 입력되었습니다." << std::endl;
		std::cout << "다시 입력해주십시오." << std::endl;
		std::cout << std::endl;
	}
};

class WithdrawException :public AccountException
{
private:
	int bal;
public:
	WithdrawException(int money) :bal(money) {}
	void ShowException()
	{
		std::cout << "잔액이 부족합니다." << std::endl;
		std::cout << "잔액 : " << bal << std::endl;
		std::cout << std::endl;
	}
};

#endif