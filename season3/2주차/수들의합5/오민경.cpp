#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	int count = 0, startIndex = 1, endIndex = 1, sum = 1;
	cin >> N;
	
	while (N != endIndex) {
		if (sum == N) {
			count++;
			sum += ++endIndex;
		}
		else if (sum < N) {
			sum += ++endIndex;
		}
		else {
			sum -= startIndex++;
		}

	}
	cout << count+1; // 자기 숫자 더하기

	return 0;
}