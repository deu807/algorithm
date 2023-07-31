n, k = map(int, input().split(' '))

coin_list = []

for _ in range(n) :
    coin_list.append(int(input()))

dp = [1] + [0] * k # dp[0] = 1로 초기값 설정

for i in coin_list :
    for j in range(i, k+1) :
        dp[j] += dp[j-i]
print(dp[k])

