import sys
input = sys.stdin.readline

n = int(input())
m = int(input())
parent = [i for i in range(n+1)] 
graph = []

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
    for i in range(1,n+1):
        link_info = list(map(int,input().split()))
        for j in range(1,n+1):
            if link_info[j-1] == 1: # 만약 연결되어있다면 union
                union(i,j)

    travel_plan = list(map(int,input().split()))
    prev = travel_plan[0]
    for i in range(1,m):
        if find(travel_plan[i]) != find(prev):
            print("NO")
            exit()
        prev = travel_plan[i]
    print("YES")
solution()
