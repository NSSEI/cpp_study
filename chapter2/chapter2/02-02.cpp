#include <iostream>

int Adder(const int &num1, const int &num2)
{
	return num1 + num2;
}

int main()
{
	const int num = 12;
	const int *ptr = &num;
	const int *(&ref) = ptr;

	std::cout << *ptr << std::endl;
	std::cout << *ref << std::endl;

	std::cout << Adder(3, 4) << std::endl;
}