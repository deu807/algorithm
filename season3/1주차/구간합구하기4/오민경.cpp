#include <iostream>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int a, b;
	int N, M;
	cin >> N >> M;
	int num;
	int S[100000] = {0};
	for (int i = 1; i <= N; i++) {
		cin >> num;
		S[i] = S[i - 1] + num;
	}
	for (int j = 1; j <= M; j++) {
		cin >> a >> b;
		cout <<  S[b] - S[a-1] << "\n";
	}
	return 0;
}
