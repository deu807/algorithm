import sys
input = sys.stdin.readline
N = int(input());
# N개의 정수를 입력받아 리스트에 저장
numbers = list(map(int, input().split()));
numbers.sort()

good_num = 0

for i in range(N):
    _range = numbers[:i] + numbers[i+1:]
    start, end = 0, len(_range) - 1
    
    while start < end:
        if _range[start] + _range[end]== numbers[i]:
            good_num += 1
            break
        elif _range[start] + _range[end] < numbers[i]:
            start += 1
        #  _range[start] + _range[end] > numbers[i] 
        else:
            end -= 1

print(good_num)