#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

string arr[101];
int board[101][101], N, M,answer[101][101];
bool check[101][101];
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
queue<pair<int, int>> q;

void bfs(int x, int y)
{
    q.push({ x, y });
    check[x][y] = true;
    while (!q.empty())
    {
        pair<int, int> cur = q.front();
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int tempX = cur.X + dx[i];
            int tempY = cur.Y + dy[i];
            if (tempX < 0 || tempX >= N || tempY < 0 || tempY >= M) continue;
            if (board[tempX][tempY] != 1 || check[tempX][tempY]) continue;
            answer[tempX][tempY] = answer[cur.X][cur.Y] + 1;
            q.push({ tempX, tempY });
            check[tempX][tempY] = true;
        }
     
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
        for (int j = 0; j < M; j++)
        {
            board[i][j] = arr[i][j] - '0';
        }
    }
    bfs(0, 0);
    cout << answer[N - 1][M - 1]+1;
}
