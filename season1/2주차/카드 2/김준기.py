import sys
from collections import deque

N = int(sys.stdin.readline())

if N == 3 : print(2)
elif N <= 4 : print(N)
else :
    queue = deque(range(1, N+1))
    while len(queue) != 1 :
        queue.popleft()
        queue.append(queue.popleft())
    print(queue[0])    

# import sys
# import math

# N = int(sys.stdin.readline())
# a = 2 ** int(math.log2(N))
# print((N-a)*2) if N != a else print(N)