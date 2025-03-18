# 13:55 ~ 15:30
import sys
input = sys.stdin.readline

n,m = map(int,input().split())
array = [list(map(int,input().split())) for _ in range(n)]
visited = [[False] * m for _ in range(n)]

dx = [0,0,1,-1] 
dy = [1,-1,-0,0]

max_sum = 0

def dfs(i,j,count,sum_value): 
    global max_sum
        
    if count == 4:
        max_sum = max(max_sum,sum_value)
        return 

    for k in range(4):
        nx,ny = i + dx[k], j + dy[k]
        if nx >= 0 and nx < n and ny>=0 and ny < m and not visited[nx][ny]:
            visited[nx][ny] = True
            dfs(nx,ny,count+1, sum_value + array[nx][ny])
            if count == 2:
                dfs(i,j,count+1, sum_value + array[nx][ny])
            visited[nx][ny] = False

def t_block(i,j):
    global max_sum
    count = 0
    sum_value = array[i][j]

    for k in range(4):
        nx,ny = i + dx[k], j + dy[k] 
        if nx >= 0 and nx < n and ny>=0 and ny < m:
            count += 1
            sum_value += array[nx][ny]

    if count == 3:
        max_sum = max(max_sum,sum_value)

    if count == 4:
        for n in range(4):
            nx,ny = i + dx[n], j + dy[n] 
            if nx >= 0 and nx < n and ny>=0 and ny < m:
                sum_value -= array[nx][ny]
            max_sum = max(max_sum,sum_value)
            sum_value += array[nx][ny]


def solution():
    global max_sum

    for i in range(n):
        for j in range(m):
            visited[i][j] = True
            dfs(i,j,1,array[i][j])
            visited[i][j] = False

            t_block(i,j)    
    
    print(max_sum)

solution()