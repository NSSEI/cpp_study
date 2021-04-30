#pragma once
#include <iostream>
#include <cstring>

class Calculator
{
private:
	int add;
	int div;
	int min;
	int mul;
public:
	void Init();
	double Add(double n1, double n2);
	double Div(double n1, double n2);
	double Min(double n1, double n2);
	double Mul(double n1, double n2);
	void ShowOpCount();
};

inline void Calculator::Init()
{
	add = 0;
	div = 0;
	min = 0;
	mul = 0;
}
inline double Calculator::Add(double n1, double n2)
{
	add++;
	return n1 + n2;
}

inline double Calculator::Div(double n1, double n2)
{
	div++;
	return n1 / n2;
}

inline double Calculator::Min(double n1, double n2)
{
	min++;
	return n1 - n2;
}

inline double Calculator::Mul(double n1, double n2)
{
	mul++;
	return n1 * n2;
}

inline void Calculator::ShowOpCount()
{
	std::cout << add << std::endl;
	std::cout << div << std::endl;
	std::cout << min << std::endl;
	std::cout << mul << std::endl;
}

class Printer
{
private:
	char str[20];
public:
	void SetString(const char *st);
	void ShowString();
};

inline void Printer::SetString(const char *st)
{
	strcpy_s(str, st);
}

inline void Printer::ShowString()
{
	std::cout << str << std::endl;
}