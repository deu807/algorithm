# 문제: [큐빙][link]

[link]: https://www.acmicpc.net/problem/5373

### 출제자 : 최은우

---
### 풀이법 : 

## 1 노가다

이 문제는 구현 문제이다.  
단순히 머릿속의 큐브를 코드로 전개하여 풀이하는 방법만이 존재할 뿐 별 다른 알고리즘을 사용하는것은 아니다.

```
/*
주사위 배치 
      B
    L U R
      F
      D

배열 배치
      3
    4 0 5
      1
      2

번호 배치
        ---------
        | 0 1 2 |
        | 3 4 5 |
        | 6 7 8 |
-------------------------
| 0 1 2 | 0 1 2 | 0 1 2 |
| 3 4 5 | 3 4 5 | 3 4 5 |
| 6 7 8 | 6 7 8 | 6 7 8 |
-------------------------
        | 0 1 2 |
        | 3 4 5 |
        | 6 7 8 |
        ---------
        | 0 1 2 |
        | 3 4 5 |
        | 6 7 8 |
        ---------

색 초기화
        ---------
        | o o o |
        | o o o |
        | o o o |
-------------------------
| g g g | w w w | b b b |
| g g g | w w w | b b b |
| g g g | w w w | b b b |
-------------------------
        | r r r |
        | r r r |
        | r r r |
        ---------
        | y y y |
        | y y y |
        | y y y |
        ---------

*/
```

