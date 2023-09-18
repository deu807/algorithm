#include <iostream>
#include <vector>
#include <queue>
#define INF 1000000000
using namespace std;

vector<pair<int, int> > graph[5001]; 
int dist[5001];

void dijkstra(int start)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    fill(dist, dist + 5001, INF);
    dist[start] = 0;
    pq.push({ start, 0 });

    while (!pq.empty())
    {
        int node = pq.top().first;
        int cost = pq.top().second;
        pq.pop();
        if (dist[node] < cost)
            continue;

        for (int i = 0; i < graph[node].size(); i++)
        {
            int next_node = graph[node][i].first;
            int next_cost = cost + graph[node][i].second;

            if (dist[next_node] > next_cost)
            {
                dist[next_node] = next_cost;
                pq.push({ next_node, next_cost });
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int V, E, P; //v는 도착지 , p는 건우의 도착지
    cin >> V >> E >> P;
    for (int i = 0; i < E; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({ b, c });
        graph[b].push_back({ a, c }); 
    }
    dijkstra(1);

    int A = dist[V]; int B = dist[P];
    dijkstra(P);
    B += dist[V];
    if (A == B)
        cout << "SAVE HIM"<<endl;
    else
        cout << "GOOD BYE" << endl;

    return 0;
}
