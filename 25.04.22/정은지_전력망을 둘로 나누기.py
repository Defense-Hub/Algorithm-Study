# 14:38 ~ 14:56

def dfs(node,visited):
    global graph
    cnt = 1
    visited[node] = True
    
    for i in graph[node]:
        if not visited[i]:
            cnt += dfs(i,visited)
    
    return cnt

def solution(n, wires):
    answer = float('inf')
    global graph
    graph = [[] for _ in range(n+1)]
    
    for v1,v2 in wires:
        graph[v1].append(v2)
        graph[v2].append(v1)
    print(graph)  

    for v1,v2 in wires:
        graph[v1].remove(v2)
        graph[v2].remove(v1)
        
        visited = [False] * (n+1)
        
        subtree_cnt = dfs(v1,visited)
        other_subtree_cnt = n-subtree_cnt
        answer = min(answer, abs(subtree_cnt-other_subtree_cnt))
        
        graph[v1].append(v2)
        graph[v2].append(v1)
        


    return answer