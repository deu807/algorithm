#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;

int a, b, cnt = 0;
vector<int> v;
bool erathos(int x)		//에라토스테네스의 체
{
	if (x < 2) return 0;

	for (int i = 2; i <= sqrt(x); i++)
	{
		if (x % i == 0) return false;
	}

	return true;
}
int prime(int x)		//소인수분해
{
	v.clear();

	for (int i = 2; i <= sqrt(x); i++)
	{
		// x의 약수 벡터에 삽입
		while (x % i == 0)
		{
			v.push_back(i);		
			x /= i;
		}
	}

	if (x > 1)	v.push_back(x);

	return v.size();		//벡터의 길이가 소수이면 언더프라임
}
int main()
{
	cin >> a >> b;

	for (int i = a; i <= b; i++)
	{
		int n = prime(i);		//소인수분해

		if (erathos(n))		cnt++;		//소인수분해한 값의 소수목록의 개수가 소수이면 cnt++
	}

	cout << cnt;
	
	return 0;
}