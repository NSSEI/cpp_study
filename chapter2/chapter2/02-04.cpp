#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <iostream>
#include <cstdlib>
#include <ctime>

int main()
{
	char str[30] = "cpp and c";
	char str2[] = " Hello ";
	char str3[30];
	std::cout << "strlen : " << std::strlen(str) << std::endl;
	std::strcat(str, str2);
	std::cout << str << std::endl;
	std::strcpy(str3, str2);
	std::cout << str3 << std::endl;
	std::cout << "strcmp : " << std::strcmp(str2, str3) << std::endl;


	std::srand(time(NULL));
	for (int i = 5; i != 0; i--)
	{
		std::cout << rand()%100 << std::endl;
	}
	return 0;
}