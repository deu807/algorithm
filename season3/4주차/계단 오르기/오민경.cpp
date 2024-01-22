#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	int stair[301];
	int point[301];
	stair[0] = 0; point[0] = 0;
	for (int i = 1; i < n+1; i++) {
		cin >> point[i];
	}
	stair[1] = point[1];
	stair[2] = point[1] + point[2];
	stair[3] = max(point[1], point[2]) + point[3];
	for (int i = 4; i < n+1; i++) {
		stair[i] = max(stair[i-2], stair[i-3]+point[i-1]) + point[i];
	}
	cout << stair[n];
	return 0;
}