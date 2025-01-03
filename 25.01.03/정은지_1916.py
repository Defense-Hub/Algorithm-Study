import sys
import heapq

input = sys.stdin.readline
n = int(input())
m = int(input())

graph = [[] for _ in range(n+1)]
for _ in range(m):
    x,y,cost = map(int,input().split())
    graph[x].append((y,cost))

start, end = map(int, input().split())
distances = [1e9 for _ in range(n+1)]
heap = []
distances[start] = 0
heapq.heappush(heap, [0, start])

def solution():
    # 다익스트라
    while(heap):
        dist, edge = heapq.heappop(heap)
        if distances[edge] < dist:
            continue

        for nedge, cost in graph[edge]:
            sum_cost = dist + cost
            if sum_cost < distances[nedge]:
                distances[nedge] = sum_cost
                heapq.heappush(heap, [sum_cost, nedge])
    
    return distances[end]

print(solution())
