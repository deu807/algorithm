#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M,S; //가수의 수,보조 PD의 수,인덱스
vector <int> v[1001]; //서로 연결
int indegree[1001]; //진입 차수
int result[1001];

void topologicalSort()
{
	queue <int> q;
	for (int i = 1; i <= N; i++)
	{
		if (indegree[i] == 0) //진입차수 0일시 큐에 삽입
			q.push(i);
	}
	while (!q.empty())
	{

		int cur = q.front();
		q.pop();
		result[S++] = cur;
		for (int i = 0; i < v[cur].size(); i++)
		{
			int next = v[cur][i]; //현재 정점와 연결된 정점
			indegree[next]--; //간선 제거
			if (indegree[next] == 0)
				q.push(next);
		}
	}
	for (int i = 1; i < N; i++)
	{
		if (indegree[i]) //큐가 비었을 때 진입차수 있을경우(사이클 존재시)
			cout << 0 << '\n';
	}
	
	for (int i = 0; i < S; i++)
	{
		cout << result[i] << '\n';
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		int x,num;
		cin >> x;
		cin >> num;
		for (int j = 1; j < x; j++)
		{
			int y;
			cin >> y;
			v[num].push_back(y);
			indegree[y]++;
			num = y;
		}
	}
	topologicalSort();
}