#include <iostream>

class FruitSeller
{
	int APPLE_PRICE;
	int numOfApples;
	int myMoney;

public:
	void InitMembers(int price, int num, int money)
	{
		APPLE_PRICE = price;
		numOfApples = num;
		myMoney = money;
	}

	int SaleApples(int money)
	{
		int num = money / APPLE_PRICE;
		numOfApples -= num;
		myMoney += money;
		return num;
	}

	void ShowSalesResult() const
	{
		std::cout << "남은 사과 : " << numOfApples << std::endl;
		std::cout << "판매 수익 : " << myMoney << std::endl;
	}
};

class FruitBuyer
{
	int myMoney;
	int numOfApples = 0;

public:
	void InitMembers(int money)
	{
		myMoney = money;
		numOfApples = 0;
	}
	bool BuyApples(FruitSeller &seller, int money)
	{
		if (money < 0)
		{
			std::cout << "wrong money" << std::endl;
			return false;
		}
		numOfApples += seller.SaleApples(money);
		myMoney -= money;
	}
	void ShowBuyResult() const
	{
		std::cout << "현재 잔액 ; " << myMoney << std::endl;
		std::cout << "사과 개수 : " << numOfApples << std::endl << std::endl;
	}
};

int main()
{
	FruitSeller seller;
	seller.InitMembers(1000, 20, 0);
	FruitBuyer buyer;
	buyer.InitMembers(5000);
	if (!buyer.BuyApples(seller, -2000))
		std::cout << "minus money" << std::endl;
	if (!buyer.BuyApples(seller, 2000))
		std::cout << "minus money" << std::endl;

	std::cout << "과일 판매자의 현황" << std::endl;
	seller.ShowSalesResult();
	std::cout << "과일 구매자의 현황" << std::endl;
	buyer.ShowBuyResult();
	return 0;
}