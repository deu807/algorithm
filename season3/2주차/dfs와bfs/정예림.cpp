#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
#define MAX 1001

int N, M, V;		//정점개수, 간선개수, 시작정점
int map[MAX][MAX] = { 0 };		//인접 행렬 그래프, 0으로 초기화
bool visited[MAX];		//정점 방문 여부
queue<int> q;

void reset()        //정점 방문 여부 0으로 초기화
{
    for (int i = 1; i <= N; i++)
    {
        visited[i] = 0;
    }
}

void dfs(int v)     //dfs는 주로 재귀함수
{
    visited[v] = true;      //방문한 곳은 true
    cout << v << " ";

    for (int i = 1; i <= N; i++) {
        // 정점과 연결되어있고 방문하지 않았으면 dfs(방문되지않은 번호)호출
        if (map[v][i] == 1 && visited[i] == 0) {        //ex) v=2라면, 2와 1 / 2와 4가 연결되어있고 1은 이미 방문했으므로 dif(4)를 호출
            dfs(i);
        }
    }
}

void bfs(int v)     //bfs '최단거리', 주로 큐 사용
{       
    q.push(v);
    visited[v] = true;      //방문한 곳은 true(1이면 방문한 곳, 0이면 방문하지 않은 곳)
    cout << v << " ";

    while (!q.empty())
    {
        v = q.front();
        q.pop();

        for (int i = 1; i <= N; i++)
        {
            // 정점과 연결되어있고 방문하지 않았으면
            if (map[v][i] == 1 && visited[i] == 0)
            { 
                q.push(i);
                visited[i] = true;      //큐에 들어왔으니 true -> 방문한 곳이 됨
                cout << i << " ";
            }
        }
    }
}

int main()
{
	cin >> N >> M >> V;

    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        map[a][b] = 1;      //정점과 정점이 연결되어있다는 표시
        map[b][a] = 1;
    }

    reset();
    dfs(V);     //시작 정점이 V이기때문에 매개변수로 넘겨줌

    cout << '\n';

    reset();        //bfs구하기 전, 방문 여부 0으로 초기화
    bfs(V);     //시작 정점이 V이기때문에 매개변수로 넘겨줌

	return 0;
}