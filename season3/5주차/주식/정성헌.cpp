#include<bits/stdc++.h>
using namespace std;
long long T, N, arr[1000001],Max,answer;
int main()
{
	cin >> T;

	while (T--)
	{
		cin >> N;
		answer = 0;
		Max = 0;
		for (int i = 0; i < N; i++)
		{
			cin >> arr[i];
		}

		for (int i = N - 1; i >= 0; i--)
		{
			Max = max(Max, arr[i]);
			answer += (Max - arr[i]);
		}
		cout << answer << "\n";
		
	}
}