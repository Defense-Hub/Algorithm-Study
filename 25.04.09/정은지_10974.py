# 15:10 ~ 15:16
import sys
input = sys.stdin.readline

n = int(input())
array = [i for i in range(1,n+1)]

# 파이썬 permutations 라이브러리 사용했을 때 코드
#from itertools import permutations

# def solution(): 
#     permus = list(permutations(array))
    
#     for permu in permus:
#         print(*permu)

# dfs + 백트래킹 사용 코드

visited = [False] * n

def dfs(path):
    if len(path) == n:
        print(*path)
        return
    
    for i in range(n):
        if not visited[i]:
            visited[i]=True
            dfs(path+ [array[i]]) 
            visited[i]=False

def solution(): 
    dfs([])

solution()