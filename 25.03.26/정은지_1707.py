# 14:35 ~ 16:05

import sys
from collections import deque
input = sys.stdin.readline

k = int(input())
# 이분그래프인지 확인 -> 그래프를 탐색하며 나와 인접한 노드를 다른 색으로 칠하기

def bfs(graph,start,color):
    queue = deque([start])

    while queue:
        node = queue.popleft()

        for i in graph[node]:
            if color[i] == -1:
                color[i] = 1 - color[node]
                queue.append(i)
            elif color[i] == color[node]:
                return False
    return True 

def check_binary_graph(graph):
    length = len(graph)
    color = [-1] * length

    for i in range(1,length):
        if not bfs(graph,i,color):
            return False
    return True

def solution():
    for _ in range(k):
        v,e = map(int,input().split()) # 정점 개수, 간선 개수
        graph = [[] for _ in range(v+1)]

        for _ in range(e):
            a,b = map(int,input().split())
            graph[a].append(b)
            graph[b].append(a)

        if check_binary_graph(graph):
            print("YES")
        else:
            print("NO")

solution()