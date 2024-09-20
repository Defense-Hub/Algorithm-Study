import sys
from collections import deque

input = sys.stdin.readline
n,m = map(int,input().split())
matrix = []
global answer
answer = 0

# 8방향(대각선 포함)
dx = [0,1,1,1,0,-1,-1,-1]
dy = [-1,-1,0,1,1,1,0,-1]
    
for i in range(n):
    matrix.append(list(map(int,input().split())))

def Bfs(x,y):
    global answer
    q = deque()
    q.append((x,y))
    visited = [[0] * m for _ in range(n)]
    distance = []

    while q:
        x,y = q.popleft()
        for i in range(8):
            nx,ny = x+dx[i], y+dy[i]
            if 0<=nx<n and 0<=ny<m and visited[nx][ny] == 0:
                visited[nx][ny] = visited[x][y]+1
                if matrix[nx][ny]!= 1:                   
                    q.append((nx,ny))
                else:
                    distance.append(visited[x][y]+1)

    answer = max(answer,min(distance))

for i in range(n):
    for j in range(m):
        if matrix[i][j] == 0:
            Bfs(i,j)

print(answer)