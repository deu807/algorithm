#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STACK_SIZE 100
typedef int Element;

Element data[MAX_STACK_SIZE];
int top;

void error(char str[])
{
  printf("%s\n", str);
  exit(1);
}

void init_stack()
{ // 스택 초기화
  top = -1;
}

int is_empty()
{ // 스택 공백상태 확인
  return top == -1;
}

int is_full()
{ // 스택 포화상태
  return top == MAX_STACK_SIZE - 1;
}

int size()
{ // 스택의 크기 반환
  return top + 1;
}

void push(Element e)
{ // PUSH 연산
  if (is_full())
  {
    error("스택 포화 에러");
  }
  data[++top] = e;
}

Element pop()
{ // POP 연산
  if (is_empty())
  {
    error("스택 공백 에러");
  }
  return data[top--];
}

Element peek()
{ // 스택의 최상단 TOP 반환
  if (is_empty())
  {
    return -1;
  }
  return data[top];
}

int precedence(char op) // 연산자를 전달받고 우선순위를 반환하는 함수
{
  switch (op)
  {
  case '(':
  case ')':
    return 0; // 우선순위 3
  case '+':
  case '-':
    return 1; // 우선순위 2
  case '*':
  case '/':
    return 2; // 우선순위 1
  }
  return -1;
}

void infix_to_postfix(char expr[]) // 중위 표현식에서 후위 표현식으로 변환
{
  int i = 0;
  char c, op;

  init_stack();
  while (expr[i] != '\0')
  { // 문자열 배열 끝까지 탐색
    c = expr[i++];
    if ((c >= 'A' && c <= 'Z'))
    { // 피연산자 => 출력
      printf("%c", c);
    }
    else if (c == '(')
    { // "(" 만나면 스택에 PUSH
      push(c);
    }
    else if (c == ')')
    { // ")" 가 나오면 "("의 전까지 모두 출력한다.
      while (is_empty() == 0)
      {
        op = pop(); // 연산자 POP
        if (op == '(')
          break; // "(" 전까지 모두 출력하기 위한 break / 괄호는 출력하지 않는다
        else
          printf("%c", op);
      }
    }
    else if (c == '+' || c == '-' || c == '*' || c == '/')
    {
      while (is_empty() == 0)
      {
        op = peek(); // 삭제 하지 않고 top 반환
        if (precedence(c) <= precedence(op))
        { // 우선순위 체크
          printf("%c", op);
          pop();
        } // 우선순위가 높은 연산자가 스택 안에 들어가 있을 경우, 우선순위가 높은 연산자를 우선 출력하고 스택에 삽입하여야 한다.
        else
          break;
      }
      push(c);
    }
  }

  while (is_empty() == 0)
    printf("%c", pop());
  printf("\n");
}

int main()
{

  char expr[100];

  scanf("%s", expr);

  infix_to_postfix(expr);

  return 0;
}