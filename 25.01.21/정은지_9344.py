import sys
input = sys.stdin.readline

t = int(input())

def find(parent,x):
    if parent[x] != x:
        return find(parent,parent[x])
    return parent[x]

def union(parent,a,b):
    a = find(parent,a)
    b = find(parent,b)
    if a < b:
        parent[b] = a
    else:
        parent[a] = b
 
def solution():
    for _ in range(t):
        n, m, p, q = map(int, input().split())
        parent = list(range(n+1))
        edgs = []

        for _ in range(m):
            u,v,w = map(int, input().split())
            edgs.append((w,u,v)) # 크루스칼 알고리즘
        
        edgs.sort()
        result = "NO"
        l = 0

        for w,u,v in edgs:
            if find(parent,u)!= find(parent,v):
                union(parent,u,v)
                l+=1
                if (u==p and v==q) or (u==q and v==p):
                    result = "YES"
            if l == n-1:
                break
        
        print(result)

solution()