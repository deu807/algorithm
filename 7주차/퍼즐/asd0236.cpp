#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
using namespace std;

typedef struct board {
	int arr[3][3];
	pair<int, int> pos;
}board;

queue<board> q;
map<string, bool> visit;
int answer_board[3][3] = {  {1, 2, 3},
							{4, 5, 6},
							{7, 8, 0} };
int dy[4] = { 0,1,0,-1 }, dx[4] = { 1,0,-1,0 }, ans;



void bfs() {
	while (!q.empty()) {
		int cur_size = q.size();
		while (cur_size--) {
			board cur;

			for (int i = 0; i < 3; i++) {
				for (int j = 0; j < 3; j++) {
					cur.arr[i][j] = q.front().arr[i][j];
				}
			}


			cur.pos = q.front().pos;
			q.pop();

			bool flag = 1;
			for (int i = 0; i < 3; i++) {
				for (int j = 0; j < 3; j++) {
					if (cur.arr[i][j] != answer_board[i][j]) {
						flag = 0;
						break;
					}
				}
			}
			if (flag) return;

			for (int i = 0; i < 4; i++) {
				int ny = cur.pos.first + dy[i];
				int nx = cur.pos.second + dx[i];
				/*cout << '\t' << cur.pos.first << ' ' << cur.pos.second << '\n';
				for (int i = 0; i < 3; i++) {
					for (int j = 0; j < 3; j++) {
						cout << cur.arr[i][j] << ' ';
					}cout << '\n';
				}cout << ans << '\n';
				cout << "\n\n\n";*/

				if (ny >= 0 && ny < 3 && nx >= 0 && nx < 3) {
					

					swap(cur.arr[cur.pos.first][cur.pos.second], cur.arr[ny][nx]);
					cur.pos = { ny,nx };
					
					/*cout << '\t' << cur.pos.first << ' ' << cur.pos.second << '\n';
					for (int i = 0; i < 3; i++) {
						for (int j = 0; j < 3; j++) {
							cout << cur.arr[i][j] << ' ';
						}cout << '\n';
					}cout << ans << '\n';
					*/
					string ar = "";
					for (int i = 0; i < 3; i++) {
						for (int j = 0; j < 3; j++) {
							ar += cur.arr[i][j] + '0';
						}
					}
					if (!visit[ar]) {
						visit[ar] = 1;
						q.push(cur);
						//cout << cur.pos.first << ' ' << cur.pos.second << '\n';
					}
					cur.pos = { ny - dy[i], nx - dx[i] };
					swap(cur.arr[cur.pos.first][cur.pos.second], cur.arr[ny][nx]);
					
				}
				
				
			}
			
			

			//if (ans > 3) return;
		}
		ans++;
	}
	ans = -1;
}

void input() {
	board start;
	int val;
	string ar = "";

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> val;
			if (!val) start.pos = { i,j };
			start.arr[i][j] = val;
			ar += val + '0';
		}
	}
	visit[ar] = 1;
	q.push(start);
}

void solve() {
	bfs();
	cout << ans;
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	input();
	solve();
}