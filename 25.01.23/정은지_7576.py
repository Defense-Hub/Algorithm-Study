import sys
input = sys.stdin.readline
from collections import deque

m,n = map(int,input().split())
array = [list(map(int,input().split())) for _ in range(n)]
# 상하좌우
dx = [0,0,-1,1]
dy = [-1,1,0,0]

def bfs():
    queue = deque()
    for i in range(n):
        for j in range(m):
            if array[i][j] == 1:
                queue.append((i,j))

    while queue:
        x,y = queue.popleft()
        
        for i in range(4):
            nx,ny = x+dx[i],y+dy[i]

            if nx>=0 and ny>=0 and nx<n and ny<m and array[nx][ny]==0:
                array[nx][ny] = array[x][y] + 1
                queue.append((nx,ny))

def is_exist_not_ripen():
    for i in array:
        for j in i:
            if j == 0:
                return True
    return False

def get_max_array():
    max_num = 0
    for i in array:
        for j in i:
            max_num = max(max_num,j)
    return max_num

def solution():
    bfs()
    
    if is_exist_not_ripen():
        print(-1)
    else:     
        print(get_max_array()-1)


solution()