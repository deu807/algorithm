#include <iostream>
#include <vector>
using namespace std;

int n, m, number, point, arr[100001]; //arr : 각 사원의 칭찬 수치 저장
vector<int> vc[100001];

void dfs(int x) {
	for (int i = 0; i < vc[x].size(); i++) {
		arr[vc[x][i]] += arr[x];
		dfs(vc[x][i]);
	}
}

int main() {
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		int tmp;
		cin >> tmp;
		if (tmp == -1) continue; //사장
		vc[tmp].push_back(i); 
	}

	for (int i = 0; i < m; i++) {
		cin >> number >> point;
		arr[number] += point;
	}
	dfs(1);

	for (int i = 1; i <= n; i++) {
		cout << arr[i] << " ";
	}

	return 0;
}