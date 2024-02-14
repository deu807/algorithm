#include<bits/stdc++.h>
using namespace std;
int arr[10], arr2[10],s;
int main()
{
	for (int i = 0; i < 10; i++)
	{
		cin >> arr[i];
	}
	arr2[0] = arr[0];
	for (int i = 1; i < 10; i++)
	{
		arr2[i] = arr2[i - 1] + arr[i];
	}
	for (int i = 0; i < 10; i++)
	{
		if (abs(100 - arr2[i]) <= abs(100 - s))
		{
			s = arr2[i];
		}
	}
	cout << s;
}