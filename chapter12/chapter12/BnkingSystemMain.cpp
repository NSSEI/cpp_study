#include "BankingCommonDecl.h"
#include "AccountHandler.h"

int main()
{
	AccountHandler sc;
	int num;

	while (true)
	{
		num = sc.Screen();
		if (num == 5) { break; }
	}

	return 0;
}