#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m, num, compliment;
int dp[100001];		//각 사원의 칭찬 수치
vector<int>person[100001];		//각 사원 번호
// 자신의 직속 후임 호출
void dfs(int x)
{
	for (int i = 0; i < person[x].size(); i++)
	{
		// 직속후임 칭찬수치 = 직속후임 칭찬 수치+자신의 칭찬 수치
		dp[person[x][i]] += dp[x];
		dfs(person[x][i]);
	}
}
int main()
{
	cin >> n >> m;

	for (int i = 1; i <= n; i++)
	{
		int a;
		cin >> a;

		if (i == 1)	continue;
		person[a].push_back(i);
	}
	
	for (int i = 0; i < m; i++)
	{
		cin >> num >> compliment;
		dp[num] += compliment;
	}
	dfs(1);
	
	for (int i = 1; i <= n; i++)
	{
		cout << dp[i] << " ";
	}

	return 0;
}