#include <iostream>
using namespace std;

int main()
{
	int arr[100] = {}; //카드에 쓰여있는 수  
	int n, m; //카드 개수, 합 
	int sum = 0;
	int max_sum = 0;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	for (int i = 0; i < n - 2; i++) 
	{
		for (int j = i + 1; j < n - 1; j++) 
		{
			for (int k = j + 1; k < n; k++) 
			{
				sum = arr[i] + arr[j] + arr[k];
				if (sum > max_sum && sum <= m) 
					max_sum = sum;
			}
		}
	}
	cout << max_sum;
	return 0;
}