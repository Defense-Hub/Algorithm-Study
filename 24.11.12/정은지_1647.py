import sys
input = sys.stdin.readline

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
    answer = 0
    # 가중치가 작은 순서대로 정렬되어있는 graph
    for c,a,b in graph:
        # a, b가 다른 집합에 속해있을 때
        if find(a) != find(b):
            # a, b 합치기
            union(a,b)
            # a, b가 같은 집합에 속해있는 경우는 제외된다
            answer += c
            last_edge = c

    return answer - last_edge # last_edge가 가중치가 가장 큰 간선이므로

n,m = map(int,input().split())
graph = []
parent = list(range(n+1))

for _ in range(m):
    a,b,c = map(int,input().split())
    graph.append((c,a,b))
graph.sort()

print(solution())
