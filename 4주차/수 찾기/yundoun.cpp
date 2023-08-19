#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, M;

vector<int>numV;

void binary_search(int x) {
	int left = 0, mid = 0, right = N - 1;

	while (left <= right) {
		mid = (left + right) / 2;

		if (numV[mid] == x) { cout << "1" << '\n'; return; }
		else if (numV[mid] > x) { right = mid - 1; } // 오른쪽 큰 값 탐색
		else { left = mid + 1; } // 왼쪽 작은 값 탐색
	}
	cout << 0 << '\n';
	return;
}


int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++) {
		int tmp;
		cin >> tmp;
		numV.push_back(tmp);
	}
	sort(numV.begin(), numV.end());

	cin >> M;

	for (int i = 0; i < M; i++) {
		int x; // 탐색할 수
		cin >> x;
		binary_search(x);
	}

	return 0;

}

