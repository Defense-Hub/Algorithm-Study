# 15:03 ~ 15:34

import sys
from collections import deque
input = sys.stdin.readline

m,n = map(int,input().split())
miro = [list(input().strip()) for _ in range(n)]
visited = [[-1] * m for _ in range(n)]
visited[0][0] = 0

def bfs():
    queue = deque([[0,0]])
    directions = [(1,0), (0,1), (-1,0), (0,-1)]

    while(queue):
        x,y = queue.popleft()

        for dir_x,dir_y in directions:
            nx, ny = x+dir_x, y+dir_y
            if 0<=nx<n and 0<=ny<m and visited[nx][ny] == -1:
                if miro[nx][ny] == "0":
                    visited[nx][ny] = visited[x][y]
                    queue.appendleft([nx,ny]) # 벽이 없는 곳 우선적으로 돌기
                elif miro[nx][ny] == "1":
                    visited[nx][ny] = visited[x][y] + 1
                    queue.append([nx,ny])

def solution():
    bfs()
    print(visited[n-1][m-1])
solution()