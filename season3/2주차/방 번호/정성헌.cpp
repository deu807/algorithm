#include<bits/stdc++.h>
using namespace std;
int N,answer,arr[10];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N;
	while (N != 0)
	{
		int tmp = N % 10;
		N /= 10;
		arr[tmp]++;
	}
	for (int i = 0; i < 10; i++)
	{
		if (i != 6 && i != 9)
			answer = max(answer, arr[i]);
	}
	answer = max(answer, (arr[6] + arr[9] + 1)/2);

	cout << answer;
}