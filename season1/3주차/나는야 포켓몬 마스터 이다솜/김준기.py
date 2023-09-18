from sys import stdin
N, M = map(int, stdin.readline().split())

poke_dict = {}
num_dict = {}
for i in range(1, N + 1) :
    pocketmon = stdin.readline().rstrip()
    poke_dict[pocketmon] = i
    num_dict[i] = pocketmon

for i in range(M) :
    a = stdin.readline().rstrip()
    if a.isdigit() : print(num_dict[int(a)])
    else : print(poke_dict[a])

