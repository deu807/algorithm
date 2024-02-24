#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, start, endd, answer, cnt;
vector<pair<int, int>> v;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> start >> endd;
		v.push_back({ start, 1 });
		v.push_back({ endd, -1 });
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++) {
		cnt += v[i].second;
		if (answer < cnt) answer = cnt;
	}
	cout << answer;

	return 0;
}