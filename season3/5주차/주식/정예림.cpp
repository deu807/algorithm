#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;

int t, n, bigger = 0;
long long answer = 0;
int main()
{
	cin >> t;

	for (int i = 0; i < t; i++)
	{
		cin >> n;

		int* arr = new int[n];

		for (int j = 0; j < n; j++)
		{
			cin >> arr[j];
		}
		// 배열 뒤로 접근
		for (int j = n - 1; j >= 0; j--)
		{
			if (bigger < arr[j]) bigger = arr[j];
			else answer += bigger - arr[j];		//팔았을 때의 최대 수익
		}

		cout << answer << endl;

		answer = 0;
		bigger = 0;
	}

	return 0;
}