#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m, answer;
int a, b, cost;
int* parent;
int findParent(int n)
{
    if (n == parent[n]) return n;
    return findParent(parent[n]);
}
// 사이클 형성 여부 판단
void unionParent(int a, int b)
{
    a = findParent(a);
    b = findParent(b);

    if (a != b) parent[a] = b;
}
int main()
{
    cin >> n >> m;

    vector<pair<int, pair<int, int>>> edge(m);
    parent = new int[n + 1];

    // 각 노드의 부모를 자기 자신으로 초기화
    for (int i = 1; i <= n; i++)
    {
        parent[i] = i;
    }

    for (int i = 0; i < m; i++)
    {
        cin >> a >> b >> cost;

        edge[i] = { cost,{a,b} };
    }

    sort(edge.begin(), edge.end());     //비용이 작은 것부터

    for (int i = 0; i < m; i++)
    {
        cost = edge[i].first;
        a = edge[i].second.first;
        b = edge[i].second.second;

        if (findParent(a) != findParent(b))
        {
            answer += cost;
            unionParent(a, b);
        }
    }

    cout << answer;

    return 0;
}