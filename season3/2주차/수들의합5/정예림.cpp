#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int start = 1, end = 1, cnt = 1, sum = 1;
	int n;

	cin >> n;

	while (n != end)
	{
		if (sum == n)
		{
			cnt++;
			sum += ++end;
		}
		else if (sum > n)
		{
			sum -= start++;
		}
		else
		{
			sum += ++end;
		}
	}

	cout << cnt;

	return 0;
}