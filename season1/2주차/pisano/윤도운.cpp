#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int N[1001];
int M[1001];
int p, cnt;
vector<int>v;

void pisano(int n, int m) {
	v.push_back(0);
	v.push_back(1);
	v.push_back(1);

	cnt = 2;

	while (true) {
		v.push_back((v[cnt - 1] + v[cnt]) % m);
		// 인접하는 두 값을 더하고 m으로 나눈값을 다음 인덱스에 저장
		cnt++;

		if (v[cnt] == 0 && v[cnt - 1] == 1) break;
		// 반복이 끝나면 종료
	}

	cout << n << " " << cnt << endl;

	v.clear();
}

// 벡터의 맨 마지막 원소가 v[cnt] = 0,
// 그리고 벡터의 맨 마지막 바로 앞의 원소 v[cnt-1] = 1 일 때,
// 다시 피보나치 수열이 1부터 시작

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> p;
	
	for (int i = 0; i < p; i++) {
		cin >> N[i] >> M[i];
		
	}

	for (int i = 0; i < p; i++) {
		pisano(N[i], M[i]);
	}

	return 0;

}

