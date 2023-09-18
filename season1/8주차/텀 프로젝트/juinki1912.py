import sys 
from collections import deque

T = int(sys.stdin.readline()) # 테케
for _ in range(T) :
    n = int(sys.stdin.readline()) # 몇명있냐
    result = n # 남은 애 count
    numbers = [0] + list(map(int, sys.stdin.readline().split(' '))) # 1번부터기 때매 0넣어줌
    # print(numbers)
    choice = [0 for _ in range(n+1)]
    for num in numbers:
        choice[num] += 1 # 번호 받은 만큼 더해줌 => 진입 차수의 개수 = 들어온 애가 몇명있냐
        # print(choice[num])
    nchoice = deque()
    for i in range(1, n+1):
        if choice[i] == 0: # 아무한테도 선택받지 못하면 
            nchoice.append(i) 
            choice[i] -= 1

    # choice에는 선택받은 사람 수이고, 선택 안받으면 -1임, nchoice에는 선택받지 못한 애들이 있음 = 모두 선택받으면 여기서 끝

    while nchoice:
        e = nchoice.pop() # 선택받지 못해서 빼냄과 동시에 result -1해줌 
        result -= 1

        choice[numbers[e]] -= 1 # 선택받지 못한 애가 선택한 사람은 자동적으로 빠지게 됨

        # 돌다가 남들한테는 선택 많이 받았는데 선택받지 못한 애의 선택만 받게 되면 빠지게 됨
        if choice[numbers[e]] == 0 :
            nchoice.append(numbers[e])

    print(n - result) # 전체에서 선택받은 애 = 선택 못받은 애
