import sys

N = int(sys.stdin.readline().strip());
# t일만큼 상담을 하면 p만큼 돈을 받는다 + t[0]와 p[0]는 사용하지 않으므로 N+1을 곱한다.
t, p = [0] * (N + 1), [0] * (N + 1)

for i in range(1, N + 1):
    t[i], p[i] = map(int, sys.stdin.readline().split())
# 결과 리스트
result = [0] * (N + 1)
for i in range(1, N + 1):
    result[i] = max(result[i], result[i - 1])
    if i + t[i] - 1 <= N:
        result[i + t[i] - 1] = max(result[i + t[i] - 1], result[i - 1] + p[i])

print(result[N])
