#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define INF 10000000000
using namespace std;

/*
    다익스트라 알고리즘(길찾기 알고리즘)
    - 출발지점 하나를 정해놓고 모든 지점에 대한 최단거리를 구하는 알고리즘
*/

int n, m, a, b, t;      //노드, 간선, 출발점, 도착점, 가중치          노드,간선,출발점,도착점,가중치
long long sdist[100001];     //최단거리
int visible[100001];        //시야에 보이는지
vector<pair<int, int>>graph[100001];
priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>>pq;        //다익스트라에서 우선순위큐 사용

void dijkstra()
{
    fill(sdist, sdist + 100001, INF);
    pq.push({ 0,0 });
    sdist[0] = 0;       //시작점의 최단 거리는 0

    while (!pq.empty())
    {
        pair<long long, int>cur = pq.top();     //우선순위가 높은 값=cur
        pq.pop();

        if (cur.second == n - 1)    break;      //도착점에 도착 -> 반복문 종료

        if (cur.first > sdist[cur.second])  continue;     //이미 처리된 노드라면 건너뛰어서 시간초과 문제 해결

        for (int i = 0; i < graph[cur.second].size(); i++)
        {
            pair<int, int>next = graph[cur.second][i];      //가중치, 노드

            if (visible[next.second] == 1) continue;        //다음 노드가 시야에 보이면 건너뜀

            if (sdist[cur.second] + next.first < sdist[next.second])        //최단 거리 업데이트
            {
                sdist[next.second] = sdist[cur.second] + next.first;
                pq.push({ sdist[next.second], next.second });
            }
        }
    }
}
int main()
{
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        cin >> visible[i];
    }

    visible[n - 1] = 0;       //마지막 도착지는 상대의 시야에 무조건 보임

    for (int i = 0; i < m; i++)
    {
        cin >> a >> b >> t;

        graph[a].push_back({ t,b });
        graph[b].push_back({ t,a });
    }

    dijkstra();

    if (sdist[n - 1] == INF) cout << -1;        //도달할 수 없는 경우
    else    cout << sdist[n - 1];

    return 0;
}