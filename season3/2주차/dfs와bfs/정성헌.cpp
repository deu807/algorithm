#include<bits/stdc++.h>
using namespace std;
int N, M, V,arr[1001][1001];
bool check[1001],check2[1001];
void dfs(int start)
{
    cout << start << ' ';
    check[start] = true;
    for (int i = 1; i <= N; i++)
    {
        if (arr[start][i] && !check[i])
            dfs(i);
    }
}
void bfs(int start)
{
    queue<int>q;
    check2[start] = true;
    q.push(start);
    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        cout << cur << ' ';
        for (int i = 1; i <= N; i++)
        {
            if (arr[cur][i] && !check2[i])
            {
                check2[i] = true;
                q.push(i);
            }
        }
    }
}
int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M >> V;
    for (int i = 0; i < M; i++)
    {
        int a, b;
        cin >> a >> b;
        arr[a][b] = arr[b][a] = 1;
    }
    dfs(V);
    cout << '\n';
    bfs(V);
}
