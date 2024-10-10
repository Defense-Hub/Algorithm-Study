import sys
input = sys.stdin.readline

n = int(input())
tree = {i: [] for i in range(1,n+1)}

for _ in range(n-1):
    a,b = map(int,input().split())
    tree[a].append(b)
    tree[b].append(a)

# 단절점(해당 정점을 제거하였을 때, 그 정점이 포함된 그래프가 2개 이상으로 나뉘는 경우)인지
def cut_vertex(node):
    # 리프 노드이거나, 자식이 하나밖에 없는 경우 그래프가 나뉘지 않는다
    if len(tree[node]) < 2:
        print('no')
    else:
        print('yes')

# 단절선(해당 간선을 제거하였을 때, 그 간선이 포함된 그래프가 2개 이상으로 나뉘는 경우)인지
def bridge(node):
    # 모든 간선은 제거시 두 개의 노드로 나뉜다 => 무조건 그래프가 2개 이상으로 나뉜다.
    print('yes')

q = int(input())
for _ in range(q):
    t,k = map(int,input().split())
    if t == 1:
        cut_vertex(k)
    elif t == 2:
        bridge(k)
