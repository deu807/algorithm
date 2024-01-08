#include<bits/stdc++.h>
using namespace std;

int N, K,cnt;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	queue<int>q;
	cin >> N >> K;
	for (int i = 1; i <= N; i++)
	{
		q.push(i);
	}
	cout << "<";
	while (!q.empty())
	{
		int cur = q.front();
		q.pop();
		cnt++;
		if (cnt == K)
		{
			if (!q.empty())
			{
				cout << cur << ", ";
				cnt = 0;
			}
			else
				cout << cur;
		}
		else
			q.push(cur);
	}
	cout << ">";
}