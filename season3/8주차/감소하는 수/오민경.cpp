#include <iostream>
#include <queue>

using namespace std;

int N;
queue <long long> q;
long long arr[1000001] = { 0 };

int main() {

	cin >> N;

	if (N < 10) {
		cout << N << endl;
		return 0;
	}

	for (int i = 0; i <= 9; i++) {
		q.push(i);
		arr[i] = i;
	}

	int index = 9;
	while (index <= N) {
		if (q.empty()) break;

		long long f = q.front();
		q.pop();
		
		int last = f % 10;

		for (int i = 0; i < last; i++) {
			q.push(f * 10 + i);
			arr[++index] = f * 10 + i;
		}
	}

	if (!arr[N]) cout << -1 << endl;
	else cout << arr[N] << endl;

	return 0;
}