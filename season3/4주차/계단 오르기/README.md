# 문제: [계단 오르기][link]

[link]: https://www.acmicpc.net/problem/2579

### 출제자 : 정예림

---

### 풀이법 :
n번째 계단까지 오르는데의 최댓값을 구하기 위해 n번째보다 이전의 계단까지 오르는데의 최댓값을 재사용하므로 dp를 활용한 문제

    dp[] : 최댓값을 저장할 배열
    arr[] : 각 계단의 점수를 저장할 배열

<br>

ex.

    dp[1] = arr[1]                                첫번째 계단을 오를 때의 최댓값과 첫번째 계단의 점수와 같음
    dp[2] = arr[1] + arr[2]                       첫번째 계단을 밟고 두번째 계단을 밟는 것    *arr[2]<arr[2]+a  (a>0)
    dp[3] = arr[1] + arr[3] or arr[2] + arr[3]    =>  dp[3]=max(arr[1], arr[2])+arr[3]

<br>
- n개의 계단이 있다고 가정

1. n-1번째 계단을 밟지 않을 때

    dp[n] = dp[n-2] + arr[n]
    
    n-2번째 계단을 오를 때의 최댓값(이전에 이미 구함)+n번째 계단의 점수

2. n-1번째 계단을 밟을 때

    dp[n] = dp[n-3] + arr[n-1] + arr[n]
    
    n-3번째 계단을 오를 때의 최댓값(이전에 이미 구함)+n-1번째 계단의 점수+n번째 계단의 점수

<br>

두 식을 하나의 식으로 나타내면 dp[n] = max(dp[n-2], dp[n-3]+arr[n-1]) + arr[n]

a < b일 때, a+c < b+c가 성립