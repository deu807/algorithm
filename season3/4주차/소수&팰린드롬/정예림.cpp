#include <iostream>
#include <string>
#include <math.h>
using namespace std;

bool erathos(int x)		//에라토스테네스의 체
{
	if (x < 2) return 0;

	for (int i = 2; i <= sqrt(x); i++)		//제곱근 사용 => 시간초과 해결
	{
		if (x % i == 0) return false;		//소수가 아니라면 false
	}

	return true;
}

/*
	1 2 5 2 1 => 0번째-4번째 비교 / 1번째-3번째 비교 모두 같으니 true 리턴
	1 2 5 2 3 => 0번째-4번째 비교 두개 다르니 false 리턴
*/
bool palin(int n)		//팰린드롬
{
	string s = to_string(n);
	for (int i = 0; i < s.size() / 2; i++)
	{
		if (s[i] != s[s.size() - i - 1])	return false;
	}

	return true;
}

int n, a;
int main()
{
	cin >> n;
	a = n;

	while (true)
	{
		if (erathos(a) && palin(a))
		{
			cout << a;
			break;
		}

		a++;
	}

	return 0;
}