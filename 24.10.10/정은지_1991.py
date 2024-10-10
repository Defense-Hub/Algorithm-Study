import sys
input = sys.stdin.readline

n = int(input())
graph = {}

# 그래프 딕셔너리 선언 (이진트리이므로 입력값은 항상 길이 3)
for _ in range(n):
    parent, child1, child2 = list(input().split())
    graph[parent] = [child1, child2]

# 전위순회
global preorder_value
preorder_value = ''

def preorder(node):
    global preorder_value
    if node != '.':  
        preorder_value += node # 루트
        preorder(graph[node][0]) # 왼쪽 노드
        preorder(graph[node][1]) # 오른쪽 노드

preorder('A')
print(preorder_value)

# 중위순회
global inorder_value
inorder_value = ''

def inorder(node):
    global inorder_value
    if node != '.':  
        inorder(graph[node][0]) # 왼쪽 노드
        inorder_value += node # 루트
        inorder(graph[node][1]) # 오른쪽 노드

inorder('A')
print(inorder_value)

# 후위순회
global postorder_value
postorder_value = ''

def postorder(node):
    global postorder_value
    if node != '.':  
        postorder(graph[node][0]) # 왼쪽 노드
        postorder(graph[node][1]) # 오른쪽 노드
        postorder_value += node # 루트

postorder('A')
print(postorder_value)