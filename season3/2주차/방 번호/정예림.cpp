#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int cnt = 1;
	int array[10] = { 0 };
	int n;

	cin >> n;

	while (1)
	{
		array[n % 10]++;
		if (n / 10 == 0)	break;
		n /= 10;
	}

	for (int i = 0; i < 10; i++)
	{
		if (i == 9 || i == 6) continue;
		cnt = max(cnt, array[i]);
	}

	cnt = max(cnt, (array[6] + array[9] + 1) / 2);

	cout << cnt;

	return 0;
}