# 15:45 ~ 16:57

# 다익스트라 알고리즘 인줄 알았으나 플로이드 워셜
# 특정 노드에서 특정 노드로 이동하는 최단 비용(거리)가 아닌 모든 노드에서 모든 노드로 가는 비용 찾아야함
# int(1e9) = 1억. 진짜 무한대는 아님
# float['inf'] = 진짜 무한대

import sys
input = sys.stdin.readline

t = int(input())

def solution():
    for _ in range(t):
        n,p,q = map(int,input().split())
        galaxy = [int(input()) for _ in range(n)] # n명의 사람이 현재 있는 은하의 번호
        graph = [[float('inf')] * (p+1) for _ in range(p+1)]

        for i in range(1,p+1): # 자기자신과의 거리 0
            graph[i][i] = 0

        for _ in range(q):
            i,j,d = map(int,input().split())
            graph[i][j] = min(graph[i][j], d)
            graph[j][i] = min(graph[j][i], d)

        # 플로이드-워셜 알고리즘으로 모든 노드 간 최단 거리 계산
        for k in range(1,p+1):
            for i in range(1,p+1):
                for j in range(1,p+1):
                    if graph[i][j] > graph[i][k] + graph[k][j]:
                        graph[i][j] = graph[i][k] + graph[k][j]
        
        answer_galaxy = 0
        answer_cost = float('inf')

        for i in range(1,p+1):
            cost = 0
            for j in range(n):
                if galaxy[j] != i: # 같은 은하면 계산하지 않기
                    # j번째 사람이 i번 은하로 가는 최솟값                   
                    cost += graph[galaxy[j]][i] ** 2

            if cost < answer_cost:
                answer_galaxy = i
                answer_cost = cost
        
        print(answer_galaxy,answer_cost)

solution()