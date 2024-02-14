#include<bits/stdc++.h>
using namespace std;

vector<int>v[100001];
int n, m,arr[100001];
void dfs(int start)
{
    stack<int>s;
    s.push(start);
    while (!s.empty())
    {
        int cur=s.top();
        s.pop();
        for (int i = 0; i < v[cur].size(); i++)
        {     
            int next = v[cur][i];
            arr[next] += arr[cur];
            s.push(next);
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        int t;
        cin >> t;
        if(t != -1) 
        {
            v[t].push_back(i);  
        }
    }
    for (int i = 0; i < m; i++)
    {
        int I = 0, w = 0;
        cin >> I >> w;
        arr[I] += w;
    }
    dfs(1);
    for (int i = 1; i <= n; i++)
    {
        cout << arr[i]<<" ";
    }
}
