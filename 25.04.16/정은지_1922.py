# 15:00 ~ 

# 최소신장트리

import sys
input = sys.stdin.readline

n = int(input())
m = int(input())
parent = [i for i in range(n+1)]
costs = []

def find(a):
    if parent[a] != a:
        parent[a] = find(parent[a])
    return parent[a]

def union(a,b):
    a = find(a)
    b = find(b)

    if a != b:
        parent[b] = a
        return True
    return False

def solution():
    for _ in range(m):
        a,b,c = map(int,input().split())
        costs.append((c,a,b))

    costs.sort()

    answer = 0
    for c,a,b in costs:
        if union(a,b):
            answer += c

    print(answer)
        

solution()