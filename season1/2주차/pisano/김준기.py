import sys

P = int(sys.stdin.readline()) 

for _ in range(P) :
    N, M = map(int, sys.stdin.readline().rstrip().split(' '))
    fibo1, fibo2 = 0, 1
    cnt = 0
    # while에 fibo1 != 0 or fibo2 != 1을 쓰게 되면 제일 처음 멈추게 됨
    while True :
        fibo1, fibo2 = fibo2, (fibo1 + fibo2) % M
        cnt += 1
        
        if fibo1 == 0 and fibo2 == 1 :
            break
        
    print(N, cnt)