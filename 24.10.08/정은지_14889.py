import sys
from itertools import combinations

input = sys.stdin.readline
n = int(input())
array = [list(map(int,input().split())) for _ in range(n)]
indexs = [i for i in range(n)]
answer = int(1e9)

lst = []
for i in combinations(indexs,n//2):
    startTeam = list(combinations(i,2))
    tmp = 0
    for j in startTeam:
        x,y = j
        tmp += array[x][y]+array[y][x]
    
    lst.append(tmp)

for i in range(len(lst)//2):
    tmp = abs(lst[i]-lst[len(lst)-i-1])
    answer=min(answer,tmp)
    
print(answer)
