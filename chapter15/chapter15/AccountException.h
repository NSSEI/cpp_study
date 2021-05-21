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
		std::cout << "0���� ���� ���� �ԷµǾ����ϴ�." << std::endl;
		std::cout << "�ٽ� �Է����ֽʽÿ�." << std::endl;
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
		std::cout << "�ܾ��� �����մϴ�." << std::endl;
		std::cout << "�ܾ� : " << bal << std::endl;
		std::cout << std::endl;
	}
};

#endif