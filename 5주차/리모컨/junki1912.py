import sys

n = int(sys.stdin.readline())  # 이동하려는 채널
m = int(sys.stdin.readline())  # 고장난 버튼의 개수

min_press = abs(n - 100)  

if m != 0: btn = set(sys.stdin.readline().split())  
else : btn = set()

for channel_range in range(999_999):
    for i in str(channel_range):
        if i in btn: 
            break
    else:
        min_press = min(min_press, abs(n - channel_range) + len(str(channel_range)))   
print(min_press)  
