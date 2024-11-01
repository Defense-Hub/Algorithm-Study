from collections import deque

def bfs(land,visited,i,j,oil):
    cnt = 1
    dx = [0,0,1,-1]
    dy = [1,-1,0,0]
            
    queue = deque([[i,j]])
    visited[i][j] = True
    columns = set()
    columns.add(j)
    
    while queue:
        x,y = queue.popleft()

        for i in range(4):
            nx,ny = x+dx[i], y+dy[i]
            
            if nx>=0 and ny>=0 and nx<len(land) and ny<len(land[0]) and not visited[nx][ny] and land[nx][ny] == 1:
                cnt += 1
                visited[nx][ny] = True
                queue.append([nx,ny]) 
                columns.add(ny)
    
    for c in columns:
        oil[c] += cnt

def solution(land):
    answer = 0
    n = len(land)
    m = len(land[0])
    visited = [[False]*m for _ in range(n)]
    oil = [0] * m 
    
    for i in range(n):
        for j in range(m):
            if land[i][j] == 1 and not visited[i][j]:
                bfs(land,visited,i,j,oil)
                  
    answer = max(oil)
    
    return answer