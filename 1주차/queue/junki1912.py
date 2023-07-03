import sys
from collections import deque
N = int(sys.stdin.readline()) 

queue = deque()

for i in range(N):
    cmd = sys.stdin.readline().split() # input은 시간초과나므로 stdin 사용 cmd[0]은 명령어 [1]은 숫자

    if cmd[0] == 'push': # 큐 추가 = queue라서 append아닌 insert로 처음 위치에 삽입
        queue.insert(0, cmd[1])

    elif cmd[0] == 'pop': # 큐 pop
        if len(queue) == 0: print(-1) 
        else: print(queue.pop())

    elif cmd[0] == 'size': # 큐 사이즈
        print(len(queue))

    elif cmd[0] == 'empty':  # 비면 1 아니면 0
        if len(queue) == 0: print(1)
        else : print(0)

    elif cmd[0] == 'front': # 없으면 -1 있으면 가장 앞의 수 = push가 계속 insert로 들어가니까 맨 마지막값이 맨 앞의 수임
        if len(queue) == 0: print(-1)
        else: print(queue[len(queue) -1])

    elif cmd[0] == 'back':  # 없으면 -1 있으면 가장 뒤의 수
        if len(queue) == 0: print(-1)
        else: print(queue[0])