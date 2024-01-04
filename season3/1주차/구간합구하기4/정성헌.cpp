#include <bits/stdc++.h>
using namespace std;

int N, M,answer,arr[100001],arr1[100001];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> M;
	for (int i = 1; i <= N; i++)
	{
		cin >> arr[i];
		arr1[i] = arr1[i - 1] + arr[i];
	}
	for (int i = 0; i < M; i++)
	{
		int n, j;
		cin >> n >> j;
		cout << arr1[j] - arr1[n - 1]<<'\n';

	}
}