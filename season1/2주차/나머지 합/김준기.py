import sys

input = sys.stdin.readline
count, number = map(int, input().split())
num_arr = list(map(int, input().split()))

arr = [0] * number
arr[0] = 1

sum_val = 0
result = 0

for e in num_arr:
    sum_val = (sum_val + e) % number
    result += arr[sum_val]
    arr[sum_val] += 1

print(result)