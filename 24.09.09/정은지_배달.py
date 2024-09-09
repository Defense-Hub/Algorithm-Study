import heapq 

def solution(N, road, K):
    answer = 0
    distance = [int(1e9)] * (N+1)
    graph = [[] for _ in range(N+1)] 
    
    # 노드의 개수 최대 50개 -> 다익스트라 알고리즘 사용
    for i in road:
        start, end, d = i
        graph[start].append((d,end))
        graph[end].append((d,start))
    
    dijkstra(1, distance, graph)
    
    for i in range(1,len(distance)):
        if distance[i] <=K:
            answer +=1
    return answer

def dijkstra(start, distance, graph):
    heap = []
    heapq.heappush(heap,[0,start])
    distance[start] = 0
    
    while heap:
        dist, now = heapq.heappop(heap)
        # 현재 거리가 더 작으면 무시
        if distance[now] < dist:
            continue       
        for i in graph[now]:
            # 이동 가능한 그래프 내 거리 중 비용 갱신
            cost = dist + i[0]
            # 계산한 비용이 현재까지 계산된 노드의 비용보다 작으면 (최단거리이면) 갱신
            if cost < distance[i[1]]:
                distance[i[1]] = cost
                heapq.heappush(heap,(cost,i[1]))
                