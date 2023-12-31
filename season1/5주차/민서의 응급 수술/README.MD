# 문제: [음악프로그램][link]

[link]: https://www.acmicpc.net/problem/20955

### 출제자 : 박상훈

---
### 풀이법 : 

Union-find 알고리즘을 이용합니다. 간선 정보들을 입력받는 과정에서, 사이클이 형성되면 안되기에
find(x) == find(y) 인 경우 이미 연결되어있던 간선을 자른다고 가정하고, answer++ 합니다.
그 경우를 제외하고는 Union(x, y) 를 진행하여 같은 집합으로 간주합니다.

분리 집합이 형성되었다면 for문을 이용하여 집합의 갯수를 세고, 집합을 연결시키는 연산의 횟수 == (집합의 갯수-1)
라는 점을 이용하여 (집합의 갯수-1) 만큼 answer값에 더하면 됩니다.