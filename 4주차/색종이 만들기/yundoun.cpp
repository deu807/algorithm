#include <iostream>
using namespace std;

int paper[129][129];
int N = 0, white =0 , blue = 0;

void input() {
	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> paper[i][j];
		}
	}
}

void Find(int x, int y, int z) {
	bool cut = false; // 색종이를 잘라야 하는지 판단
	int color = paper[x][y];  // 색종이의 시작점의 색
	for (int i = x; i < x + z; i++) {
		for (int j = y; j < y + z; j++) {
			if (paper[i][j] != color) {  // 탐색을 진행하다가 다른처음과 다른 색이 나올 경우 
				cut = true; // 잘라야함
				break;
			}
		}
	}
	if (cut) {
		Find(x, y, z / 2);
		Find(x, y + z / 2, z / 2);
		Find(x + z / 2, y, z / 2);
		Find(x + z / 2, y + z / 2, z / 2);
	}
	else {
		if (color == 1) blue++;
		else white++;
	}

}

int main() {
	// 1. (x, y, z)
	// 2. (x, y, z/2)
	// 3. (x, y + z/2, z/2)
	// 4. (x + z/2, y, z/2)
	// 5. (x + z/2, y + z/2 , z/2)

	input();

	Find(0, 0, N);

	cout << white << endl << blue;
	return 0;
}