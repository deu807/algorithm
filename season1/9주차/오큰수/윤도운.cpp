#include <iostream>
#include <algorithm>
#include <string>
#include <stack>

using namespace std;

int N;
stack<int> s;

int ans[1000001]; // 오큰수를 담을 배열
int ary[1000001]; // 입력받을 배열

void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> ary[i];
	}
}

// 스택에 들어갈 값은 각 배열의 원소값이다.
// 즉 배열의 마지막부터 시작하여 스택에 푸시하고 인덱스를 뒤에서 감소시켜가면서 배열의 원소값을 비교한다.
// 가장 마지막으로 입력받은 원소값이 스택에 가장 먼저 들어갈 것이며 즉, 마지막 원소의 오큰수는 항상 -1일 것이다. 이후 마지막 원소가 스택에 푸시되며 N-2번째 인덱스부터 하나씩 감소하며 탐색을 진행한다.
// 스택에 있는 top이 현재 수열의 값보다 커질때까지 pop한다
// 스택에 있는 top이 현재 수열보다 크기 때문에 현재 수열의 오큰수는 스택에 있는 top이 된다.

void solution() {
	for (int i = N - 1; i >= 0; i--) {
		while (!s.empty() && s.top() <= ary[i]) {
			// 스택이 공백일때까지
			// 스택의 top의 값보다 같거나 작은 값이 나올때까지 pop
			s.pop();
		}
		if (s.empty()) ans[i] = -1;
		else ans[i] = s.top();

		s.push(ary[i]);
	}

	for (int i = 0; i < N; i++)
		cout << ans[i] << " ";

}

void solve() {
	input();
	solution();
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solve();

	return 0;

}

