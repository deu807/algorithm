import sys
from collections import deque

# N은 미로 개수, M은 미로의 크기
N, M = map(int, sys.stdin.readline().rstrip().split()) 

# 2차원 list
maze_list = [list(map(int, list(sys.stdin.readline().rstrip()))) for _ in range(N)]

queue = deque([(0, 0)])

# ['상','하','좌','우']
distance_x = [0, 0, -1, 1]
distance_y = [-1, 1, 0, 0]

while queue:
    x, y = queue.popleft() 
    for i in range(0, 4):
        next_x, next_y = x + distance_x[i], y + distance_y[i]
        # next의 좌표가 미로 안에 존재하고, next좌표가 벽이 아니라면
        if 0 <= next_x < N and 0 <= next_y < M and maze_list[next_x][next_y] == 1:
            maze_list[next_x][next_y] = maze_list[x][y] + 1
            # 새로운 좌표를 큐에 추가
            queue.append((next_x, next_y))

maze_list[0][0] = 1
# print(maze_list)
# 최종적으로 도착한 곳의 값을 출력
print(maze_list[N-1][M-1])