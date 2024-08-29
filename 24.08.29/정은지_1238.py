import heapq
import sys

# 다익스트라 알고리즘
def dijkstra(start):
    q = []
    heapq.heappush(q,(0,start))
    distance = [int(1e9)] * (n+1)
    distance[start] = 0

    while q:
        d, now = heapq.heappop(q)
        if d > distance[now]:
            continue
        for i in graph[now]:
            # i는 (끝지점, 시간)
            val = d + i[1]
            if val< distance[i[0]]:
                distance[i[0]] = val
                heapq.heappush(q,(val,i[0]))
    return distance

input = sys.stdin.readline
# n명의 학생이 x번 마을에 모여 파티. m개의 단방향 도로 존재
n,m,x = map(int,input().split())

answer = 0
graph = [[] for _ in range(n+1)]

for _ in range(m):
    start,end,time = map(int,input().split())
    graph[start].append((end,time))

for i in range(1,n+1):
    # i to x
    go = dijkstra(i)
    # x to i
    back = dijkstra(x)
    answer = max(answer, go[x]+back[i])

print(answer)

