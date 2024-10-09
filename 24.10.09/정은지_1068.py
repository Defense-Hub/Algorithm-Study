import sys

input = sys.stdin.readline
n = int(input())
array = list(map(int,input().split()))

# graph의 index는 트리의 순서, 원소에는 [해당 노드의 숫자, [해당 노드의 자식노드들]]
graph = [[] for _ in range(n)]

root_node = 0
for i in range(n):
    # 루트 노드가 아니면
    if array[i] != -1:
        graph[array[i]].append(i)
    else:
        root_node = i

# 지워질 노드들 구하는 함수
def delete_dfs(graph,delete_node):
    global delete_nodes
    for i in graph[delete_node]:
        delete_nodes.add(i)
        delete_dfs(graph,i)

global delete_nodes
delete_node = int(input())
delete_nodes = set()
delete_nodes.add(delete_node)

delete_dfs(graph,delete_node)

# graph에서 지워질 노드들 제거
for i in range(n):
    if i in delete_nodes:
        graph[i] = []
    else:
        for j in delete_nodes:
            if j in graph[i]:
                graph[i].remove(j)


# 그래프의 리프노드 개수 구하기
global answer
answer = 0

def dfs(graph,node):
    global answer
    if graph[node]:
        for i in graph[node]:
            dfs(graph,i)
    else:
        answer += 1

if delete_node != root_node:
    dfs(graph,root_node)

print(answer)