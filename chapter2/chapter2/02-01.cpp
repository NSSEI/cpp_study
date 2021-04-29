#include <iostream>

void IncreaseOne(int &num)
{
	++num;
}

void ChangeSign(int &num)
{
	num *= (-1);
}

void SwapPtr(int* &ptr1, int* &ptr2)
{
	int *tmp = ptr1;
	ptr1 = ptr2;
	ptr2 = tmp;
}

int main()
{
	int num = 1;
	IncreaseOne(num);
	std::cout << (num) << std::endl;
	ChangeSign(num);
	std::cout << (num) << std::endl;

	int num1 = 5;
	int *ptr1 = &num1;
	int num2 = 10;
	int *ptr2 = &num2;

	SwapPtr(ptr1, ptr2);
	std::cout << *ptr1 << std::endl;
	std::cout << *ptr2 << std::endl;
	return 0;
}