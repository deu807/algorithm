# 문제: [슈퍼 마리오][link]

[link]: https://www.acmicpc.net/problem/2851

### 출제자 : 정예림

---

### 풀이법 :

    다음 버섯을 먹었을 때의 누적 점수(sum)와 다음 버섯을 먹지 않았을 때의 누적 점수(answer) 중 절댓값을 이용하여 100에 더 가까운 값을 출력
    
    *answer의 초깃값은 0이며, 선택된 누적값을 answer에 저장하는 형식


<br>
- 다음 버섯을 먹었을 때, 100에 더 가깝다면 실제로 마리오가 버섯을 먹게 됨
<br>
abs(100-sum) < abs(100-answer)
<br>
answer=sum
<br><br>
- 다음 버섯을 먹지 않았을 때가 100에 더 가깝다면 마리오가 버섯을 더이상 먹지않고 중단하게 됨
<br><br>
- 100에 가까운 수가 2개라면 큰 값을 선택
<br>
abs(100-sum) == abs(100-answer)
<br>
answer=max(answer, sum)