# find
def find(parent, node) :
    if parent[node] != node :
        parent[node] = find(parent, parent[node])
    return parent[node]

# union
def union(parent, node1, node2) :
    union_node1 = find(parent, node1)
    union_node2 = find(parent, node2)
    if union_node1 < union_node2 :
        parent[union_node2] = union_node1
    else :
        parent[union_node1] = union_node2

import sys

N = int(sys.stdin.readline())
M = int(sys.stdin.readline())
graph = [list(map(int, sys.stdin.readline().split())) for _ in range(N)]
parents = list(range(N))
plan = list(map(int, sys.stdin.readline().split()))

for i in range(N):
    for j in range(N):
        if graph[i][j] == 1:
            union(parents, i, j)
            
result = "YES"
for i in range(1, M):
    if parents[plan[i] - 1] != parents[plan[0] - 1]:
        result = "NO"
        break

print(result)
