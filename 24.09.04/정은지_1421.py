# 나무의 개수, 나무 자를 때 드는 가격, 나무 팔 때 가격
n,c,w = map(int,input().split())
lst = []

for _ in range(n):
    lst.append(int(input())) 

answer = 0

for i in range(1, max(lst)+1):
    cost = 0
    # 나무의 단위
    for wood in lst:
        cnt, remain = divmod(wood, i) 
        if remain:
            profit = (cnt * i * w) - (cnt * c)
        else:
            profit = (cnt * i * w) - ((cnt-1) * c)

        if profit > 0:
            cost += profit
    answer = max(answer,cost)

print(answer)