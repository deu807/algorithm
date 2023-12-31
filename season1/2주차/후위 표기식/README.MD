# 문제: [후위 표기법][link]

[link]: https://www.acmicpc.net/problem/1918

### 출제자 : 윤도운

---

## 풀이법 :

후위 표기법 (Postfix) : 연산자를 피연산자 뒤에 표기한다.
ex) AB+, 5AB\*+

후위 표기 수식의 계산에는 스택이 사용된다. 계산을 위해 전체 수식을 왼쪽에서 오른쪽으로 스캔하고, 스캔 과정에서 피연산자가 나오면 무조건 스택에 저장한다. 연산자가 나오면 스택에서 피연산자 두 개를 꺼내 연산을 실행하고 그 결과를 다시 스택에 저장한다. 이 과정은 수식이 모두 처리될 때 까지 반복되고, 마지막으로 스택에는 최종 계산 결과만 하나 남는다.

## pseudo code

### - calc_postfix(expr)

    스택 초기화;
    for 항목 in expr
      do if (항목이 피연산자이면)
          then push(항목);
        else if (항목이 연산자이면)
            then second <- pop();
            first <- pop();
            temp <- first op second; // op 는 +_*/중의 하나
            push(temp);
    result <- pop();

---
