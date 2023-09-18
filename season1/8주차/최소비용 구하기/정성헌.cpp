#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define INF 100000000
using namespace std;

vector<pair<int, int> >graph[100001]; //간선 정보 담은 배열
int dist[1001]; //최단 거리 저장 

void dijkstra(int start)
{
	//pair(노드 번호, 최소 거리)
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; //최소 힙 구현
	fill(dist, dist + 1001, INF); //dist 배열의 모든 값을 INF로 설정
	dist[start] = 0;
	pq.push(make_pair(start, 0));
	
	while (!pq.empty())
	{
		int node = pq.top().first; //first 정점, second 거리
		int cost = pq.top().second;
		pq.pop();
		if (dist[node] < cost) continue;

		for (int i = 0; i < graph[node].size(); i++)
		{
			int next_node = graph[node][i].first;
			int next_cost = cost + graph[node][i].second;

			if (dist[next_node] > next_cost)
			{
				dist[next_node] = next_cost;
				pq.push(make_pair(next_node, next_cost));
			}
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M; //도시의 개수,버스의 개수
	cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		int a, b, c; //출발 도시 번호, 도착 도시 번호, 버스 비용
		cin >> a >> b >> c;
		graph[a].push_back({ b, c }); 
	}

	int start, end;
	cin >> start >> end;

	dijkstra(start);
	cout << dist[end] << '\n';
}