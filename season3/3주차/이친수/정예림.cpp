#include <iostream>
#include <algorithm>
using namespace std;

int n;
long long dp[90];
int main()
{
	cin >> n;

	dp[1] = 1;
	dp[2] = 1;

	//두단계 전에 01을 넣는 것
	for (int i = 3; i <= n; i++)
	{
		dp[i] = dp[i - 2] + dp[i - 1];
	}

	cout << dp[n];

	return 0;
}