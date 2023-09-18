#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

int N, M, A, B, C;
int start, arrive;

int visit[1001]; // 각각의 도시까지의 비용을 담을 배열
vector<pair<int, int>> v[1001]; // <도착할 도시, 비용>


void input() {
	cin >> N >> M;

	v[0].push_back(make_pair(0, 0));
	memset(visit, 98765432, sizeof(visit)); // 모든 비용 최대로 초기화
	for (int i = 0; i < M; i++) {
		cin >> A >> B >> C;
		v[A].push_back(make_pair(B, C));
	}

	cin >> start >> arrive;
}

void solution(int a) {
	priority_queue < pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > pq;
	// 우선순위 큐 오름차순 정렬로 선언

	// <비용, 도착도시>
	pq.push(make_pair(0, a)); 
	visit[a] = 0; // 출발 도시 비용 = 0

	while (!pq.empty()) {
		int cost = pq.top().first; // 현재 도시까지의 비용
		int x = pq.top().second; // 현재 도시
		pq.pop();

		// 현 도시 까지의 비용이 이미 기록된 비용보다 클때는 패스
		if (visit[x] < cost)
			continue;

		// x 도시와 이어진 도시들을 탐색
		for (int i = 0; i < v[x].size(); i++) {
			int nx = v[x][i].first; // 다음 도시
			int ncost = cost + v[x][i].second; // 다음 도시까지 비용

			// 기록 되어진 비용보다 지금 비용이 더 작을 경우 큐에 푸시
			if (visit[nx] > ncost) {
				pq.push(make_pair(ncost, nx));
				visit[nx] = ncost; // 비용 다시 기록
			}
		}
	}
}

void solve() {
	input();
	solution(start);
	cout << visit[arrive];
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);



	solve();

	return 0;

}

