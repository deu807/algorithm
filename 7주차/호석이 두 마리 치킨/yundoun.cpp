#include <iostream>
#include <algorithm>
#include <vector>
#define INF 1000000000;

using	namespace std;

int N, M;
int ary[101][101];
int ans_T = INF; // 시간의 최소값
pair<int, int> ans_P;  // 건물 번호

void input() {

	cin >> N >> M; // 건물의 개수 : N , 도로의 개수 M


	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (i == j) {
				continue;
			}
			ary[i][j] = INF; // 한번에 갈 수 없는 거리는 초기화
		}
	}

	for (int i = 0; i < M; i++) { // 길 뚫어주기
		int A, B;
		cin >> A >> B;
		ary[A][B] = 1;
		ary[B][A] = 1;
	}
}

void solution() {

	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (ary[i][j] > ary[i][k] + ary[k][j]) {
					ary[i][j] = ary[i][k] + ary[k][j];
				}
			}
		}
	} // 모든 정점에서 모든 정점으로 방문하는 최단 거리를 저장

	for (int i = 1; i <= N; i++) {
		for (int j = i + 1; j <= N; j++) {
			int Time_Sum = 0; // 시간의 합
			for (int k = 1; k <= N; k++) {
				Time_Sum += min(ary[k][i] * 2, ary[k][j] * 2);
			}
			if (ans_T > Time_Sum) {
				ans_T = Time_Sum; // 최소값 구하기
				ans_P = make_pair(i, j);
			}
		}
	} // 치킨집을 지을 두 정점의 조합 중 기리의 합이 가장 짧은 조합 구하기

}

void solve() {
	input();
	solution();
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solve();

	cout << ans_P.first << " " << ans_P.second << " " << ans_T << endl;

	return 0;

}