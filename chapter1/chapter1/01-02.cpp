// main �Լ� �ڿ� main �Լ����� ȣ��� �Լ� ���� �Ұ���
// �Լ� overloading ������ �Լ� �̸� or �Ű����� ������ �޶���Ѵ�.

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