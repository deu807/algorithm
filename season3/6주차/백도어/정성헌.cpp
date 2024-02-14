#include<bits/stdc++.h>
#define INF 9999999999
using namespace std;

int N, M, a, b, t; //노드,간선,출발점,도착점,가중치
long long dist[100001]; //최단거리
int v[100001]; //시야에 보이는지
vector<pair<int, int>>graph[100001]; 
priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>>pq;
void dijkstra()
{
    fill(dist, dist + 100001, INF);
    pq.push({ 0,0 });
    dist[0] = 0;
    while (!pq.empty())
    {
        pair<long long, int>cur = pq.top();
        pq.pop();
        if (cur.second == N - 1)break;
        if (cur.first > dist[cur.second]) continue;
        for (int i = 0; i < graph[cur.second].size(); i++)
        {
            pair<int,int>next = graph[cur.second][i]; //가중치,노드
            if (v[next.second] == 1) continue;
            if (dist[cur.second] + next.first < dist[next.second])
            {
                dist[next.second] = dist[cur.second] + next.first;
                pq.push({ dist[next.second], next.second });
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        cin >> v[i];
    }
    v[N - 1] = 0;
    for (int i = 0; i < M; i++)
    {
        cin >> a >> b >> t;
        graph[a].push_back({ t,b });
        graph[b].push_back({ t,a });
    }
    dijkstra();
    if (dist[N - 1] == INF)
        cout << -1;
    else
        cout << dist[N - 1];
}
