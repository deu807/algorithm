# 문제: [미로 탐색][link]

[link]: https://www.acmicpc.net/problem/2178

### 출제자 : 김준기

---
### 풀이법 : BFS
BFS(Breath-First search)는 말 그대로 너비 우선 탐색이며(가까운 경로부터 탐색하는 방법),

이번 코드에서는 BFS의 효율적 삽입과 삭제를 위해서 deque를 사용했습니다.

맨 처음에 2차원 list로 미로를 만듭니다. 
여기서 deque에 0, 0를 append해주고, 이 값으로 x와 y의 이동 값을 줘서 인접한 x, y에 값을 할당하는 것입니다. 
범위에 벗어나지 않는 경우와 벽이 아닌 경우에는 값을 +1 해줍니다.


