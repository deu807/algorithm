N, M = map(int, input().split(' ')) # 첫째 줄에 카드의 개수 N(3 ≤ N ≤ 100)과 M(10 ≤ M ≤ 300,000) = 21
card_list = list(map(int, input().split(' ')))

result = []

for i in range(0, len(card_list)-2) :
    for j in range(i+1, len(card_list)-1) :
        for k in range(j+1, len(card_list)) :
            if card_list[i] + card_list[j] + card_list[k] <= M : 
                result.append(card_list[i] + card_list[j] + card_list[k])

print(max(result))