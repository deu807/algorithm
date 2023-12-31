# 문제: [민준이와 마산 그리고 건우][link]

[link]: https://www.acmicpc.net/problem/18223

### 출제자 : 박상훈

---
### 풀이법 : 

다익스트라 알고리즘을 활용하여 문제를 해결합니다.

제한 시간 1초, 정점의 개수가 최대 5000인 관계로 O(N^3)의 시간 복잡도를 가지는 플로이드 와샬 알고리즘으로는 해결할 수 없습니다.

다익스트라를 활용하여 하나의 배열 안에 특정 정점에 대한 최단 거리들을 저장하도록 다익스트라 코드를 작성합니다.
문제에서 요구하는 바는 1번째 정점부터 V번째 정점까지 최단 거리인 경로들 중 건우가 서있는가 이기 때문에

1번째 정점부터 V번째 정점까지 최단거리 == 1번째 정점부터 건우가 있는 정점까지의 최단거리 + 건우가 있는 정점부터 V번째 정점까지 최단거리
인가를 판단하면 됩니다. 참일 경우 "SAVE HIM", 거짓일 경우 "GOOD BYE"를 출력하면 됩니다.