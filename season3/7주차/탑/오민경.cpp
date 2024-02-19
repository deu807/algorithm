#include <iostream>
#include <stack>
using namespace std;

stack <pair<int, int>> t; //탑의 번호(1)와 높이(2) 저장
int N;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 1; i <= N; i++) {
		int height;
		cin >> height;

		while (!t.empty()) {
			if (t.top().second > height) { //현재 입력받은 수가 앞서 스택에 넣은 높이보다 작으면 -> 현재 위치에 top번호가 표기
				cout << t.top().first << " ";
				break;
			}
			else 
			{
				t.pop();
			}
				
		}
		if (t.empty()) cout << "0" << " "; //맨 앞의 수신탑은 0

		t.push({ i, height });
	}

	return 0;
}