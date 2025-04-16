# 13:11 ~ 13:59

import sys
input = sys.stdin.readline

r,c = map(int,input().split())
board = [list(input().strip()) for _ in range(r)]
visited = set(board[0][0])
answer = 0

dx = [0,0,1,-1]
dy = [1,-1,0,0]

def Dfs(x,y,cnt):
    global answer
    answer = max(answer,cnt)

    for i in range(4):
        nx,ny = x+dx[i], y+dy[i]
        if 0<=nx<r and 0<=ny<c and board[nx][ny] not in visited:
            visited.add(board[nx][ny])
            Dfs(nx,ny,cnt+1)
            visited.remove(board[nx][ny])

Dfs(0,0,1)
print(answer)