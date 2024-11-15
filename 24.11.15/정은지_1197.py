import sys
input = sys.stdin.readline
sys.setrecursionlimit(100000)

def find(x):
    if x != parent[x]:
        parent[x] = find(parent[x])
    return parent[x]

def union(a,b):
    a = find(a)
    b = find(b)

    if a<b:
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

v,e = map(int,input().split())
graph = []
parent = [i for i in range(v+1)]

for _ in range(e):
    a,b,c = map(int,input().split())
    graph.append((c,a,b))

graph.sort()

print(solution())