def find(parent, node) :
    if parent[node] != node : parent[node] = find(parent, parent[node])
    return parent[node]

def union(parent, node1, node2) :
    union_node1 = find(parent, node1)
    union_node2 = find(parent, node2)
    if union_node1 < union_node2 : parent[union_node2] = union_node1
    else : parent[union_node1] = union_node2

result = 0
cnt = 0 # 횟수

import sys
input = sys.stdin.readline
# 학교 N개의 연결 정보 M개
N, M = map(int, input().split())

# M(남), W(여)
univ = list(input().split())
# 입력받은 학교 정보
univ_edge = []
for _ in range(M) :
    u, v, d = map(int, input().split())
    univ_edge.append((d, u - 1, v - 1))

univ_node = [n for n in range(N)] # 순서대로 
univ_edge.sort() # 가중치 순대로 -> 크루스칼
# print(univ_edge)

for d, u, v in univ_edge :
    # 여자 남자 and 연결 안되면
    if univ[u] != univ[v] and find(univ_node, u) != find(univ_node, v) :
        # 연결시켜줌과 동시에 값 저장 and 횟수 + 1
        union(univ_node, u, v)
        result += d
        cnt += 1
    # mst만들면 나오기
    if cnt == N - 1 : break

# 사이클이 직전 mst만들어졌다면
if cnt == N - 1 : print(result)
# 안 만들어지면
else: print(-1)