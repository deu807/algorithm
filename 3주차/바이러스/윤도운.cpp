#include <iostream>
#include <vector>
using namespace std;

int pc[101][101] = { 0, };
int visit[101] = { 0, };
int answer = 0; // 정답
int N; // 컴퓨터 수

void dfs(int x) {
	visit[x] = 1; // 방문했음 표시
	answer++; // 컴퓨터 감염 횟수 증가

	for (int i = 1; i <= N; i++) {
		if (visit[i] == 0 && pc[x][i] == 1) {
			dfs(i);
		} // 방문하지 않았고, 간선이 존재하면
	}
}

int main() {
	
	int N2; // 번호 쌍의 개수
	int a = 0, b = 0;

	cin >> N >> N2;

	for (int i = 0; i < N2; i++) {
		cin >> a >> b;
		pc[a][b] = pc[b][a] = 1;  // 입력받은 간선 2차원 배열에 저장 => 인접 행렬 방식
	}

	dfs(1);

	cout << answer - 1;
}