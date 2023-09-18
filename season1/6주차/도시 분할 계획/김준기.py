def find(parent, node) :
    if parent[node] != node :
        parent[node] = find(parent, parent[node])
    return parent[node]

def union(parent, node1, node2) :
    union_node1 = find(parent, node1)
    union_node2 = find(parent, node2)
    if union_node1 < union_node2 :
        parent[union_node2] = union_node1
    else :
        parent[union_node1] = union_node2

def kruskal(edges, n) :
    edges.sort(key = lambda x : x[2])
    parents = [i for i in range(n + 1)]
    total_cost, max_cost = 0, 0

    for edge in edges :
        A, B, C = edge
        if find(parents, A) != find(parents, B) :
            union(parents, A, B)
            total_cost += C
            max_cost = max(max_cost, C)
    return total_cost - max_cost

import sys 
# N은 집의 개수, M은 길의 개수
N, M = map(int, sys.stdin.readline().rstrip().split())
cost_info = []

for i in range(M):
    # A번 집과 B번 집을 연결하는 길의 유지비가 C
    A, B, C = map(int, sys.stdin.readline().rstrip().split())
    cost_info.append((A, B, C))

print(kruskal(cost_info, N))
