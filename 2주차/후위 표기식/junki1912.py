# + - 
# * /
# ( 
import sys
from collections import deque
N = sys.stdin.readline().rstrip() # rstrip엔터제거

queue = deque()
result = ''

for char in N :
    # 알파벳은 바로 추가
    if char.isalpha() :
        result += char  
    # 괄호 추가
    elif char == '(' :
        queue.append(char)
    # * /
    elif char == '*' or char == '/' :
        # queue에 마지막 값이 동일한 순서면 바로 전에 있던 queue에 result에 넣어주는 거
        while queue and queue[-1] in ['*', '/'] :
            result += queue.pop()
        queue.append(char)
    elif char == '+' or char == '-' :
        # 우선순위가 제일 낮은 상황이면 바로 전에 있던 queue에 result추가
        while queue and queue[-1] not in '(' :
            result += queue.pop()
        queue.append(char)
    else : # ')'
        while queue and queue[-1] not in '(' :
            result += queue.pop()
        if len(queue) != 0 :
            queue.pop() # '('는 그냥 pop

while queue : # pop안된 queue가 있을 때 
    result += queue.pop()
print(result)

