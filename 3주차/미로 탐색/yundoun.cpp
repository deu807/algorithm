#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int N, M; 
int vist[101][101]; 
int maze[101][101];		// 미로
int dist[101][101];		// 이동거리 저장

int x_dir[4] = { -1, 1, 0, 0 }; 
// 정점의 인접한 좌, 우를 확인하기 위한 좌표
int y_dir[4] = { 0, 0, -1, 1 }; 
// 정점의 인접한 상, 하를 확인하기 위한 좌표

queue < pair<int, int> > q;		// 탐색 좌표 저장하는 큐

void input() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		string n;
		cin >> n;
		for (int j = 0; j < M; ++j) {
			maze[i][j] = n[j] - '0';
		}
	}
}

void solution(int startX, int startY) {
	vist[startX][startY] = 1;  
	// 입력받은 좌표를 방문했다고 1로 표시
	q.push(make_pair(startX, startY));
	// 탐색 좌표로 저장
	dist[startX][startY]++;
	// 시작 좌표에서 이동한 칸을 1로 지정

	// 큐가 빌때까지 = 모든 좌표를 탐색할 때 까지 반복
	while (!q.empty()) { 
		
		int x = q.front().first;
		int y = q.front().second;
		// 큐에 들어가 있는 front 좌표를 현재 좌표로 저장

		// 곧 front 좌표를 탐색 할 것이기 떄문에 큐에서 미리 제거
		q.pop();

		// 현재 좌표와 인접한 상하좌우 좌표 탐색
		for (int i = 0; i < 4; ++i) {
			int newX = x + x_dir[i];
			int newY = y + y_dir[i];

			// 인접한 좌표가 
			// 미로 내에 존재하는지 ( maze[newX][newY] == 1 )
			// 방문한 적이 없는지 ( !vist[newX][newY] )
			// 이동이 가능한지 확인 (0 <= newX && newX < N) && (0 <= newY && newY < M) 
			if (maze[newX][newY] == 1 && !vist[newX][newY] &&
				(newX >= 0) && (newX < N) && (newY >= 0) && (newY < M)) {

				vist[newX][newY] = 1; // 인접 좌표 방문했다고 표시
				q.push(make_pair(newX, newY)); // 인접 좌표 큐에 저장
				dist[newX][newY] = dist[x][y] + 1; // 인접한 좌표까지 이동한 거리 더해서 저장
			}

		}
	}
}

void solve() {
	input();
	solution(0,0);
	cout << dist[N - 1][M - 1];
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solve();

	return 0;

}

