# 문제: [나머지 합][link]

[link]: https://www.acmicpc.net/problem/10986

### 출제자 : 최은우

---
### 풀이법 : 

## 1. 나머지 규칙

이 문제를 풀기 위해서 먼저 알아야하는 나머지 규칙이 있다.
임의값 x,y와 나누는 값 n을 두고
```
x mod n = a
y mod n = a
```
일때 x - y 는 항상 n의 배수 즉
> x-y mod n = 0 

의 값을 가진다

예시
```
100 mod 7 = 2
149 mod 7 = 2
(100 - 149) mod 7 = 0

8 mod 3  = 2
11 mod 3 = 2
(11 - 8) mod 3 = 0
```

## 2. 문제의 이해

예시인 값을 살펴보자
```
n = 3
arr = [1,2,3,1,2]

3으로 나누어 떨어지게되는 배열의 연속된 숫자의 합은

기준  1 2 3 1 3    sum    mod3
  1   1 2           3       0
  2   1 2 3         6       0
  3   1 2 3 1 2     9       0
  4     2 3 1       6       0
  5       3         3       0
  6       3 1 2     6       0
  7         1 2     3       0
```
부분수열의 합 sum을 mod n 을 하였을 경우 0의 값이 나오는 가짓수는
이렇게 7가지의 경우의 수가 나온다

추가 예시를 들어보자

```
n = 3
arr = [3,3,3]
기준  3 3 3   sum    mod3
  1   3         3       0
  2   3 3       6       0
  3   3 3 3     9       0
  4     3       3       0
  5     3 3     6       0
  6       3     3       0
```

## 3. 1번 규칙과 2번 이해를 바탕으로 수식 생성

arr 에서 인덱스 3군데를 0,i,j 로 두고 위의 나머지 규칙을 이용하면 다음과 같은 사실을 유추해낼 수 있다.

```
0 < i < j 라고 가정하고
1. sum(i,j) = arr[i] + arr[i+1]+ arr[i+2] + ... + arr[j]
라는 식을 정의하고

2. sum(0,i) mod n = x
3. sum(0,j) mod n = k
일때

4. sum(i,j) mod n = 0
이다
```
구간 합에서 mod n 이 같은 값들을 구하면 되기에 mod n 값을 인덱스로 두고 해당 배열에서의 가중치를 더하면 된다.

추가로
> 5. sum(i,j) mod n = 0

가 있고
e < i 일때
> 6. sum(e,i) mod n = 0

라면
> 7. sum(e,j) mod n = 0

도 성립됨을 알아야 한다

<br />

## 4. 문제 풀이


``` js
dp = Array(n)
dp[0] = 1 // 위 항목의 7번 식이 성립된다는건 이전의 값이 계속 보관되어야 하기에 dp를 사용한다
sum = 0
remain = 0
result = 0
for(let i = 0 ; i < arr.length; i++){
  // 각 배열의 합을 구한다
  sum += arr[i] 

  // 각 배열의 합에서 나머지를 구함
  remain = sum % n 

  // 해당 배열의 값을 더하는건 이전에 더한 값 중에 나머지가 같은 값이 있다는것이며
  // 상단의 2,3번 의 식을 성립한다는 의미므로 들어있는 값을 저장한다
  // +1 이 아닌 dp의 저장된 값을 더하는 이유는 7번식의 이유로 저장하게 된다 
  result += dp[remain] 

  // 해당 나머지를 가지게 된 수가 증가하였으니 1을 올려준다
  dp[remain]++
}
return result

```

조금 더 부가적인 예시를 들자면
```
n = 3
arr = [1,3,3,3,2]
dp = [1,0,0]
index   1 3 3 3 2   sum    mod3     dp      result      출력값                  출력값에 있는 값을 인덱스로 표현
  1     1            1      1     [1,1,0]     +0      
  2     1 3          4      1     [1,2,0]     +1        [3]                             [1]
  3     1 3 3        7      1     [1,3,0]     +2        [3], [3,3]                      [1], [1,2]
  4     1 3 3 3     10      1     [1,4,0]     +3        [3], [3,3], [3,3,3]             [1], [1,2], [1,2,3]
  5     1 3 3 3 2   12      0     [2,4,0]     +1        [1,3,3,3,2]                     [0,1,2,3,4]
```

이 이상 상세한 설명은 더이상은 다메요

---
