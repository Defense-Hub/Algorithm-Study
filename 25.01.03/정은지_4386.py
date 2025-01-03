import math

n = int(input())
parent = list(range(n+1))

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
    points = []
    edges = []

    for _ in range(n):
        x,y = map(float,input().split())
        points.append((x,y))

    for i in range(n-1):
        for j in range(i+1,n):
            edges.append((math.sqrt((points[i][0] - points[j][0])**2 + (points[i][1] - points[j][1])**2), i, j))
    
    edges.sort()

    for edge in edges:
        cost, x, y = edge

        if find(x) != find(y):
            union(x,y)
            answer += cost

    return answer

print(round(solution(),2))
