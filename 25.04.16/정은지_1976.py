# 15:05 ~ 15:27 (다시 품)

import sys
input = sys.stdin.readline

n = int(input())
m = int(input())
parent = [i for i in range(n+1)]

def find(a):
    if parent[a] != a:
        parent[a] = find(parent[a])
    return parent[a]

def union(a,b):
    a = find(a)
    b = find(b)

    if a < b:
        parent[b] = a
    else:
        parent[a] = b

def solution():
    for i in range(n):
        informations = list(map(int,input().split()))
        for j in range(n):
            if informations[j] == 1:
                union(i+1,j+1)

    plan = list(map(int,input().split()))
    root = parent[plan[0]]

    for i in plan:
        if find(i) != root:
            print("NO")
            exit()

    print("YES")

solution()
