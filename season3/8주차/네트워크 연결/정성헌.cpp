#include<bits/stdc++.h>
using namespace std;

int N, M,parent[1001],answer;
vector<pair<int, pair<int, int>>>graph;
int getParent(int x) //부모 노드 찾는 함수
{
    if (parent[x] == x) return x;
    else
        return parent[x] = getParent(parent[x]);
}
bool findParent(int x, int y) //같은 부모 가지는지 확인
{
    x = getParent(x);
    y = getParent(y);
    if (x == y) return true;
    else return false;
}
void unionParent(int x,int y) //두 부모 노드 합치기
{
    x = getParent(x);
    y = getParent(y);
    if (x < y) parent[y] = x;
    else parent[x] = y;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M;
    for (int i = 1; i <= N; i++)
    {
        parent[i] = i;
    } 
    for (int j = 0; j < M; j++)
    {
        int a=0, b=0, c=0;
        cin >> a >> b >> c;
        graph.push_back({ c, { a,b } });
    }
    sort(graph.begin(), graph.end()); //가중치 기준으로 정렬
    for (int i = 0; i < graph.size(); i++)
    {
        
        if (!findParent(graph[i].second.first, graph[i].second.second)) //사이클이 형성하지 않는 경우
        {         
            answer += graph[i].first;
           unionParent(graph[i].second.first, graph[i].second.second);        
        }      
    }
    cout << answer;
    
}
