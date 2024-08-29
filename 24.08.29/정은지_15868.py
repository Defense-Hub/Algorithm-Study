from itertools import combinations
import sys
input = sys.stdin.readline

n,m = map(int,input().split())
city = []
chicken = []
house = []

def CalculateDistance(chicken):
    value= 0
    for i in house:
        nx,ny = i
        distance = int(1e9)
        for j in chicken:
            x,y = j
            distance = min(distance,abs(nx-x) + abs(ny-y))
        value += distance
    return value

for i in range(n):
    lst = list(map(int,input().split()))
    city.append(lst)
    for j in range(n):
        if lst[j] == 1:
            house.append((i,j))
        if lst[j] == 2:
            chicken.append((i,j))

lst = combinations(chicken, m)

answer = int(1e9)
for i in lst:
    answer = min(answer,CalculateDistance(i))

print(answer)