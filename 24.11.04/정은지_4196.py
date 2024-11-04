import sys
input = sys.stdin.readline
sys.setrecursionlimit(1000000)

def dfs(node):
    visited[node] = True
    for i in graph[node]:
        if not visited[i]:
            dfs(i)
    queue.append(node) 

def reversed_dfs(node):
    visited[node] = True
    ids[node] = idx
    for i in reversed_graph[node]:
        if not visited[i]:
            reversed_dfs(i)

t = int(input())
for _ in range(t):
    n,m = map(int,input().split())
    # 그래프
    graph = [[] for _ in range(n+1)]
    # 역방향 그래프
    reversed_graph = [[] for _ in range(n+1)]

    # x가 넘어지면 y도 넘어짐 -> 방향 존재 -> 그래프에 방향대로 삽입
    for _ in range(m):
        x,y = map(int,input().split()) 
        graph[x].append(y)
        reversed_graph[y].append(x)

    # 역방향 탐색으로 scc 찾기 => 코사라주 알고리즘
    queue = []
    visited = [False] * (n+1)

    # 정방향 탐색으로 정점 쌓기
    for node in range(1,n+1):
        if not visited[node]:
            dfs(node)

    # 정방향 탐색으로 SCC 찾기
    # 각 노드가 속한 SCC의 번호 저장하는 배열
    ids = [-1] * (n+1)
    # SCC의 개수 = idx
    idx = 0
    visited = [False] * (n+1)

    while queue:
        node = queue.pop()
        if not visited[node]:
            reversed_dfs(node)
            idx += 1

    #print(ids)

    # SCC들의 진입차수 저장하는 배열
    ind = [0] * idx
    for node in range(1, n+1):
        for i in graph[node]: # 이어진 정점을 검사 (정방향 그래프)
            if ids[node] != ids[i]: # 만약 두 정점의 SCC 번호가 다르면
                ind[ids[i]] += 1 # 이어진 정점의 SCC의 진입차수를 증가시킨다.
    # 진입차수가 0인 SCC의 개수가 정답이 된다. => SCC가 0이면 외부에서 들어오는 간선이 없으므로 시작점이 될 수 있다.
    answer = 0
    for i in range(idx):
        if not ind[i]:
            answer += 1
    print(answer)