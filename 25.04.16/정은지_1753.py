# 14:01 ~ 14:30

# 가중치 + 최단 그래프 -> 다익스트라 알고리즘 
import sys
import heapq
input = sys.stdin.readline

v,e = map(int,input().split())
k = int(input())
graph = [[] for _ in range(v+1)]
dist = [int(1e9)] * (len(graph))

def dijkstra(graph,start):
    dist[start] = 0
    heap = [(0,start)] # 가중치, start 노드

    while heap:
        cur_dist, cur_node = heapq.heappop(heap)
        
        if cur_dist>dist[cur_node]: # 지금 검사할 노드가 이미 계산된 최단 거리보다 크면 검사할ㄹ 필요가 없음
            continue

        for weight, next_node in graph[cur_node]: # 다음 노드들 검사
            next_dist = cur_dist+weight
            if next_dist < dist[next_node]: # 최단 거리 갱신일 경우
                dist[next_node] = next_dist
                heapq.heappush(heap,(next_dist,next_node))

    return dist


def solution():
    for _ in range(e):
        u,v,w = map(int,input().split())
        # u에서 v로 가는 가중치 w인 간선이 존재
        graph[u].append((w,v))

    dijkstra(graph,k)

    for i in range(1,len(dist)):
        if dist[i]==int(1e9):
            print("INF")
        else:
            print(dist[i])

solution()