# 문제: [펠린드롭 분할][link]

[link]: https://www.acmicpc.net/problem/1509

### 출제자 : 최은우

---
### 풀이법 : 

## 1 dp 문제임을 이해

이 문제가 왜 dp 인가를 이해해야하는데  
펠린드롭은 앞뒤가 같은 문자열

|문자열|펠린드롭인가|
|------|-----------|
|b     |          O|
|aaa   |          O|
|aabb  |          X|
|aba   |          O|
|abcba |          O|

이렇게 생겼다.

그러면 abcba를 예시로 든다면  
abcba가 펠린드롭이려면  
bcb가 펠린드롭이여야 하고  
c 가 펠린드롭이여야 한다

n의 길이 문자열 str 에서 펠린드롭의 문자열을 찾으려면  
0<= start <= end <= n 의 start 와 end 에서  
start ~ end 까지가 펠린드롭이려면  
start+1 ~ end-1 까지가 펠린드롭이여야 하며  
str[start] === str[end] 여야 한다.

이것만 가지고 dp 문제인가 하면 그렇지 않다

우리는 펠린드롭을 분해할건데 최소의 수로 분해하여야 한다.

aaaaba라는 문자열을 펠린드롭만큼 분해한다고 하면  
```
a  a  a  a  b  a 
aa a  a  b  a
aaa  a  a  b  a
aaaa  b  a
.
.
.
a  aa  a  b  a
a  aaa  b  a
.
.
.
a  a  a  aba


```
등등 이렇게 분해가 가능한데 우리가 필요한건 최소의 분해이므로  
어떤 start 지점을 잡았을때 이전까지의 최소 펠린드롭의 분할의 수 가 있을 때  
end 지점까지 펠린드롭이 된다면  
```
dp[end] = min(dp[start-1] +1, dp[end])
```
이라는 식을 만들어 사용할 수 있다

```
ex)

str = aaaaba
start = 3
end = 5
str[3]~ str[5] = "aba"
str[2] 까지의 펠린드롭의 나열

a a a
aa a
a aa
aaa

그중 최소가 되는 분해는 aaa 즉 1개 이므로
dp[2]는 1이였을것

따라서 
dp[5] = dp[2] +1
      = 2
"aaa" , "aba"
가 나오게 됨


```

## 2. 펠린드롭 표 만들기

펠린드롭은 start와 end를 두어 만들게 되다보니 2차원 배열을 만들어야 한다.
```
Declare dp[rows][columns]

For i from 0 to rows-1
    For j from 0 to columns-1
        dp[i][j] = false
    End For
End For
```
펠린드롭의 스타트는 두가지가 존재한다

본인 스스로 한자릿수 문자열이거나
같은 문자열의 두자릿수 문자열이거나

a**b**a  
a**bb**a

그래서 맨처음 펠린드롭의 초기화는 
i === i 인 값과
i === i+1 인 값을 비교하여 초기화를 한다

```
For i from 0 to rows-1
    dp[i][i] = true
End For

For i from 1 to rows-1
    if(str[i-1] === str[i]) dp[i-1][i] = true
End For

```

그 후 우리는  
dp[end] = min(dp[start-1] +1, dp[end]) 라는 식을 사용할 것이기에  
end로 for문을 돌리며 
start지점을 end 보다 작게 하면서 2중 for문을 사용하면서 해당 점화식을 사용하면 풀 수 있다.