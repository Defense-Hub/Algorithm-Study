import sys
input = sys.stdin.readline

n = int(input())
m = int(input())

graph = []
parent = list(range(n+1))
for _ in range(m):
    a,b,c = map(int,input().split())
    if a!=b:
        graph.append((c,a,b))

graph.sort()

def find(x):
    if parent[x] != x:
        return find(parent[x])
    return parent[x]

def union(a,b):
    a = find(a)
    b = find(b)
    if a < b:
        parent[b] = a
    else:
        parent[a] = b

def solution():
    answer = 0
    for c,a,b in graph:
        if find(a) != find(b):
            union(a,b)
            answer += c
    return answer


print(solution())
