#include <vector>
#include <iostream>
#include <string>
#include <queue>
using namespace std;

int n, sum, number, a, b;
priority_queue<int, vector<int>, greater<int>> pq; //오름차순으로 정렬된 우선순위 큐

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> number;
		pq.push(number);
	}
	
	while (pq.size() != 1) { //제일 작은 두 개씩 더하기
		a = pq.top();
		pq.pop();
		b = pq.top();
		pq.pop();

		sum += a + b;
		pq.push(a + b);
	}
	cout << sum;

	return 0;
}