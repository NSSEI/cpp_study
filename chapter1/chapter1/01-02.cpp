// main 함수 뒤에 main 함수에서 호출된 함수 정의 불가능
// 함수 overloading 에서는 함수 이름 or 매개변수 선언이 달라야한다.

#include <iostream>

void swap(int& a, int& b)
{
	int tmp;
	tmp = a;
	a = b;
	b = tmp;
}

void swap(char* a, char* b)
{
	char tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}

int main(void)
{
	int n1 = 10, n2 = 20;
	swap(n1, n2);
	std::cout << n1 << ' ' << n2 << std::endl;

	char ch1 = 'A', ch2 = 'B';
	swap(&ch1, &ch2);
	std::cout << ch1 << ' ' << ch2 << std::endl;
	return 0;
}