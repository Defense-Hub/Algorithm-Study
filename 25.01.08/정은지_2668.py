import sys
from itertools import combinations
input = sys.stdin.readline

n = int(input())
array = [[] for _ in range(n+1)]
answer = []

def dfs(prev,num):
    visited[prev] = True

    for i in array[prev]:
        if not visited[i]:
            dfs(i,num)
        elif visited[i] and i == num: # 사이클 생성
            answer.append(i)
    
for i in range(1, n+1):
    array[int(input())].append(i)

for i in range(1, n+1):
    visited = [False] * (n+1)
    dfs(i,i)

print(len(answer))
for i in answer:
    print(i)


