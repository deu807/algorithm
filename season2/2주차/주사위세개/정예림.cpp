#include <iostream>
using namespace std;

int main() {

	int a, b, c;
	int price;
	int max;

	cin >> a >> b >> c;

	if (a == b && b == c) //세개가 같을 때
	{
		price = 10000 + a * 1000;
		cout << price;
	}
	else if (a != b && b != c && c != a) //세개가 다를 때
	{
		max = a > b ? (a > c ? a : c) : (b > c ? b : c);
		price = max * 100;
		cout << price;
	}
	else
	{
		if (a == b)
		{
			price = 1000 + a * 100;
			cout << price;
		}
		else if (b==c)
		{
			price = 1000 + b * 100;
			cout << price;
		}
		else if (c==a)
		{
			price = 1000 + c * 100;
			cout << price;
		}
	}
}