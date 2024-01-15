#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int N, M;
	cin >> N >> M;
	int arr[51];
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	int tmp = 0;
	int count = 0;
	for (int i = 0; i < N; i++) {
		tmp += arr[i];
		if (tmp > M) { ++count; tmp = 0; i--; }
		else if (tmp == M) { ++count; tmp = 0; }
	}
	if (tmp > 0) { count++; }
	cout << count;
	return 0;
}