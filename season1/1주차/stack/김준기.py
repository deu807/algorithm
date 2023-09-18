import sys
N = int(sys.stdin.readline())

stack = []

for i in range(N):
    cmd = sys.stdin.readline().split()  # input은 시간초과나므로 stdin 사용 cmd[0]은 명령어 [1]은 숫자

    if cmd[0] == 'push': # 스택 추가
        stack.append(cmd[1])

    elif cmd[0] == 'pop': # 스택 pop
        if len(stack)==0: print(-1)
        else: print(stack.pop())
        
    elif cmd[0] == 'size': # 스택 사이즈
        print(len(stack))

    elif cmd[0] == 'empty': # 비면 1 아니면 0
        if len(stack)==0: print(1)
        else: print(0)
    
    elif cmd[0] == 'top' : # 비면 -1 있으면 제일 최근 꺼
        if len(stack)==0: print(-1)
        else: print(stack[-1])