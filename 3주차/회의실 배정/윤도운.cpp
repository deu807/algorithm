#include <iostream>
#include <algorithm>

using namespace std;

pair<int, int> arr[100001];
int N, a, b, cnt = 1;

void input() {
	

	cin >> N;
	
	for (int i = 0; i < N; i++) {
		cin >> b >> a;
		arr[i] = { a, b };
		// 끝나는 시간을 먼저 넣기
	}
}

void solution() {
	sort(arr, arr + N);
	// 일찍 끝나는 순서대로 정렬
	int end = arr[0].first;
	// 가장 먼저 끝나는 회의 시간 저장
	for (int i = 1; i < N; i++) {
		if (end <= arr[i].second) {
			// 가장 먼저 끝나는 회의시간보다 같거나 늦은
			// 회의 시작시간 탐색
			cnt++;
			end = arr[i].first;
			// 다음 회의 종료시간으로 갱신
		}
	}

	cout << cnt;
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

	return 0;

}

