import sys
sys.setrecursionlimit(10**6)
input = sys.stdin.readline

n,m = map(int, input().split())
parent = [i for i in range(n+1)] 

# 노드 n의 루트노드 return
def find(n):
    if parent[n] != n:                  
        parent[n] = find(parent[n])     
    return parent[n]                    

# a, b가 다른 집합에 속해있을 때 같은 집합으로 합치는 함수
def union(a, b):
    a = find(a)         
    b = find(b)         
    if a < b:           
        parent[b] = a   # b의 부모노드를 a로 설정
    else:               
        parent[a] = b  # a의 부모노드를 b로 설정

def solution():
    for i in range(m):
        value,a,b = map(int, input().split())
        if value == 0:
            union(a,b)
        else:
            if find(a) == find(b):
                print("YES")
            else:
                print("NO")
        
solution()
