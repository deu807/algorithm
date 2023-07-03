#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 배열을 이용한 스택 구현

#define MAX_STACK_SIZE 10000
typedef int Element;

Element data[MAX_STACK_SIZE];
int top;

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
{ // 삽입 연산
  if (is_full())
  {
    printf("에러 : 스택 포화상태\n");
  }
  data[++top] = e;
}

Element pop()
{ // 삭제 연산
  if (is_empty())
  {
    return -1;
  }
  return data[top--];
}

Element peek()
{ // 삭제 하지 않고 top 반환
  if (is_empty())
  {
    return -1;
  }
  return data[top];
}

int main()
{
  int n = 0;
  char str[7];
  int num;

  scanf("%d", &n);
  fgetc(stdin);

  init_stack();

  for (int i = 0; i < n; i++)
  {
    scanf(" %s", str);

    if (strcmp(str, "push") == 0)
    {
      scanf("%d", &num);
      fgetc(stdin);
      push(num);
    }
    else if (strcmp(str, "pop") == 0)
    {
      printf("%d\n", pop());
    }
    else if (strcmp(str, "empty") == 0)
    {
      printf("%d\n", is_empty());
    }
    else if (strcmp(str, "size") == 0)
    {
      printf("%d\n", size());
    }
    else if (strcmp(str, "top") == 0)
    {
      printf("%d\n", peek());
    }
  }

  return 0;
}