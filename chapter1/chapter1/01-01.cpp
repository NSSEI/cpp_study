#include <iostream>

// 01 - 01 을 공부하며 배운것
// 지역변수는 스택이어서 나중에 선언되는 변수가 주솟값이 더 작다.
// cout 은 \0 이 나올때까지 출력하도록 동작한다.
// 스택은 후입선출(LIFO, Last-In First-Out) 방식에 따라 동작하므로, 가장 늦게 저장된 데이터가 가장 먼저 인출된다.
// 스택 영역은 메모리의 높은 주소에서 낮은 주소의 방향으로 할당됩니다.

int main_a(void)
{
	int arr[10];
	int result = 0;

	for (int i = 0; i < 10; i++)
	{
		std::cout << "arr[" << i << "] number : ";
		std::cin >> arr[i];
		result += arr[i];
	}

	std::cout << result;
	return 0;
}

int main_b(void)
{
	char name[100];
	int num;

	std::cout << "name : ";
	std::cin >> name;
	std::cout << "num : ";
	std::cin >> num;

	std::cout << "name : " << name << std::endl;
	std::cout << "num : " << num;
	return 0;
}

int main_c(void)
{
	int num;
	std::cin >> num;

	for (int i = 1; i < 10; i++)
	{
		std::cout << num * i << std::endl;
	}
	return 0;
}

int main_d(void)
{
	int num;

	while (1)
	{
		std::cout << "sales : ";
		std::cin >> num;

		if (num == -1)
		{
			std::cout << "Exit";
			break;
		}
		else
		{
			std::cout << "salary : " << 50 + num * 0.12 << std::endl;
		}
	}
	return 0;
}