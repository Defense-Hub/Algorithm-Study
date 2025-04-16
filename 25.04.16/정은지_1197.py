# 14:31 ~ 14:57
# 최소 스패닝 트리 
# 주어진 그래프의 모든 정점들을 연결하는 부분 그래프 중에서 그 가중치의 합이 최소인 트리
# 사이클이 존재하지 않는 트리
# 유니온 파인드 알고리즘

import sys
sys.setrecursionlimit(100000)
input = sys.stdin.readline

v,e = map(int,input().split())
parent = [i for i in range(v+1)]
informations = []

def union(a,b):
    a = find(a) # 부모 노드 값 설정
    b = find(b)

    if a != b: 
        parent[b] = a
        return True
    return False

def find(a):
    if parent[a] != a:
        parent[a] = find(parent[a])
    return parent[a]


def solution():
    answer = 0
    for _ in range(e):
        a,b,c = map(int,input().split())
        informations.append((c,a,b))

    informations.sort()

    for c,a,b in informations:
        if union(a,b):
            answer += c

    print(answer)
        

solution()