#include <iostream>
using namespace std;

int main()
{
	int a, b, c;
	int result;

	cin >> a >> b >> c;

	if (a % 2 == 0 && b % 2 == 0 && c % 2 == 0) //a, b, c가 짝수 일때
	{
		cout << a * b * c;
	}
	else //a, b, c 중 홀수가 하나라도 있을 때
	{
		result = 1;
		if (a % 2 == 1)
		{
			result = result * a;
		}
		if (b % 2 == 1)
		{
			result = result * b;
		}
		if (c % 2 == 1)
		{
			result = result * c;
		}
		cout << result;
	}
}