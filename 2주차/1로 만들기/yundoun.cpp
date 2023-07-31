#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	
	int N;
	
	cin >> N;

	vector<int>DP(1000001); // 배열의 Index가 연산하는 숫자
	DP[1] = 0; // N 이 1일 경우 연산 X
	DP[2] = 1;
	DP[3] = 1;


	for (int i = 4; i <= N; i++) {
		DP[i] = DP[i - 1] + 1;

		if (i % 3 == 0) {
			DP[i] = min(DP[i], DP[i / 3] + 1);
		}
		if (i % 2 == 0) {
			DP[i] = min(DP[i], DP[i / 2] + 1);
		}
	}
	
	cout << DP[N];
}