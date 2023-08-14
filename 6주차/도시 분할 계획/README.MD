# 문제: [도시 분할 계획][link]

[link]: https://www.acmicpc.net/problem/1647

### 출제자 : 김준기

---
### 풀이법 : 
1. union-find algorithm 사용
2. kruskal algorithm 사용

union-find를 사용하여 부모 노드를 지정해줍니다. 낮은 가중치를 부모 노드로 설정하는 것이 핵심입니다.

kruskal algorithm을 사용하여 mst를 만들면 되는 문제입니다. 
문제에서 요구하는 것은 마을의 유지비를 최소화하는 것으로 mst를 구하면 되는 것이고,
실질적으로 구하는 것은 마을을 두개로 분리해야하므로 mst에서 가장 가중치가 큰 간선 하나를 빼면 정답으로 인정됩니다.

---