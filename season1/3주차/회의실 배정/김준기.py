import sys
input = sys.stdin.readline
N = int(input()) # < 100_000
times = []
for _ in range(N) :
    start, end = map(int, input().split())
    times.append((start, end))
times.sort(key = lambda x: (x[1], x[0])) # 끝나는 시간이 같으면 시작 시간을 기준으로 함

cnt = 0
endtime = 0
for start, end in times :
    if start >= endtime :
        cnt += 1
        endtime = end
print(cnt)