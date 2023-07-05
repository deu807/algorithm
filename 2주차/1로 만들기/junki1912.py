dp = [0, 0, 1, 1] # 1일 경우는 0번, 2와 3일 경우는 1번
N = int(input())
dp = dp + [0] * (N-3)
for i in range(4, N+1):
    dp[i] = dp[i-1] + 1 #1을 빼는 경우
    if i % 2 == 0 : dp[i] = min(dp[i], dp[i//2] + 1)
    if i % 3 == 0 : dp[i] = min(dp[i], dp[i//3] + 1)
print(dp[N])
 