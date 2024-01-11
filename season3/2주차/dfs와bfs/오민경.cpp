#include <iostream>
#include <queue>
using namespace std;
//dfs, bfs 함수 따로 만들기 때문에 전역변수로 선언
#define MAX_VALUE 1001
int N, M, V; // N : 정점 개수, M : 간선 개수, V : 시작할 정점의 번호
int Array[MAX_VALUE][MAX_VALUE] = { 0 }; //이동할 수 있는지를 0과 1로 나타낸 인접행렬
int visit[MAX_VALUE]; //갔던 곳을 표시하기 위해 선언한 배열로 기본 0으로 초기화

void dfs(int v) {
	cout << v << ' '; //v로 방문
	visit[v] = 1; //방문한 곳을 0에서 1로 바꾸어 표시
	for (int i = 1; i <= N; i++) {
		if (visit[i] == 1 || Array[v][i] == 0) // 방문한 곳이거나, 이동할 수 없는 곳이면
			continue; // 실행하지 않고 다음 줄에 있는 dfs(i)를 호출
		dfs(i); 
	}
}
void bfs(int v) {
	queue<int> q;
	q.push(v);
	visit[v] = 0;	//방문한 노드를 visit 1에서 0으로 변경 - dfs 실행 후 visit이 모두 1이므로 반대로 수행
	while (!q.empty()) {
		v = q.front(); 
		cout << q.front() << ' ';	
		q.pop();	
		for (int i = 1; i <= N; i++) {		
			if (visit[i] == 0 || Array[v][i] == 0)
				continue;
			q.push(i);
			visit[i] = 0;
		}

	}
}

int main() {
	int x, y;
	cin >> N >> M >> V;
	for (int i = 0; i < M; i++) {
		cin >> x >> y;
		Array[x][y] = Array[y][x] = 1; // 갈 수 있는 곳을 1로 표시, 인접행렬 표시
	}
	dfs(V);
	cout << '\n';
	bfs(V);
	return 0;
}
