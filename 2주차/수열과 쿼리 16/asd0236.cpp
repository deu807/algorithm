#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define INF 987654321;

int n, m, arr[100001], tree[400001], j, v, opt;

int minInd(int x, int y) {
	if (x == -1) return y;
	if (y == -1) return x;

	//같은 경우 더 작은 인덱스 리턴
	if (arr[x] == arr[y]) return x < y ? x : y;
	else return arr[x] <= arr[y] ? x : y;
}

int init(int start, int end, int node) {
	if (start == end) return tree[node] = start;
	int mid = (start + end) / 2;

	return tree[node] = minInd(init(start, mid, node * 2), init(mid + 1, end, node * 2 + 1));
}

// start : 시작 인덱스, end : 끝 인덱스
// left, right : 구간 합을 구하고자 하는 범위
int find_min(int start, int end, int node, int left, int right) {
	if (left > end || right < start) return -1;			//범위 밖인 경우
	if (left <= start && end <= right) return tree[node];	//범위 안인 경우
	int mid = (start + end) / 2;
	return minInd(find_min(start, mid, node * 2, left, right), find_min(mid + 1, end, node * 2 + 1, left, right));
}

// dif : 수정할 값
int update(int start, int end, int node, int index) {
	if (index < start || index > end) return tree[node]; // 범위 밖인 경우
	//범위 안인 경우
	if (start == end) return tree[node]; // 리프 노드를 만난 경우
	int mid = (start + end) / 2;
	
	return tree[node] = minInd(update(start, mid, node * 2, index), update(mid + 1, end, node * 2 + 1, index));
}

void input() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	init(0, n - 1, 1);
	cin >> m;
	for (int i = 0; i < m; i++) {

		cin >> opt >> j >> v;
		if (opt == 1) {
			arr[j - 1] = v;
			update(0, n - 1, 1, j - 1);
			
		}
		else {
			cout << find_min(0, n - 1, 1, j - 1, v - 1) + 1 << '\n';
		}

	}
}


int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	input();
}