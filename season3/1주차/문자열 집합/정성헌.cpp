#include <bits/stdc++.h>
using namespace std;

int N, M,answer;
map<string, int>m;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		string s;
		cin >> s;
		m.insert({ s,0 });
	}
	for (int i = 0; i < M; i++)
	{
		string temp;
		cin >> temp;
		if (m.find(temp) != m.end())
			answer++;
	}
	cout << answer;	
}