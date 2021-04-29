#include <iostream>

// 디폴트 매개변수는 오른쪽부터 채워야한다.

int BoxVolume(int len, int height = 1, int width = 1)
{
	return len * height * width;
}

double BoxVolume(double len, double height = 10, double width = 10)
{
	return len * height * width;
}


int main_f(void)
{
	std::cout << BoxVolume(1) << std::endl;
	std::cout << BoxVolume(1.1111) << std::endl;
	return 0;
}