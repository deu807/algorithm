# 문제: [구간합구하기4][link]

[link]: https://www.acmicpc.net/problem/11659

### 출제자 : 윤도운

---

### 풀이법

구간 합의 핵심 이론은 우선 합 배열을 먼저 구해야한다.

배열 A가 있을 때, 합 배열 S의 정의는 다음과 같다

<pre><code>S[i] = A[0] + A[1] + A[2] + A[3] .... A[i-1] + A[i] 
// A[0]부터 A[i]까지의 합</code></pre>

이렇게 합 배열을 미리 구해 놓으면 기존 배열의 일정 범위의 합을 구하는 시간 복잡도가  
O(N)에서 O(1)로 감소한다.

※ A[i]에서 A[j]까지의 배열 합을 합 배열 없이 구하는 경우, 최악의 경우는 i가 0이고 j가 N인 경우이기 때문에

합 배열 S를 만드는 공식  
<strong>=> S[i] = S[i-1] + A[i]</strong>

구간 합을 구하는 공식  
<strong>=> S[j] - S[i-1]</strong>

<pre><code>index 0  1  2  3  4  5
배열A 15 13 10 7  3  12</code></pre>

위와 같은 배열 A가 있을 때, 2~5의 구간합을 구하기 위해서는 S[5] - S[1]을 구하면 된다.

우선 합 배열을 만들어보자.

<pre><code>index   0  1  2  3  4  5
배열A   15 13 10 7  3  12
합배열S 15 28 38 45 48 60</code></pre>

S[5] = 60  
S[1] = 28  
따라서 2~5의 구간합은 32이다.
