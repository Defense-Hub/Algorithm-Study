from collections import deque
import sys
input = sys.stdin.readline

n,k = map(int,input().split())
array = []
virus = []

# 배열 초기화
for i in range(n):
    array.append(list(map(int,input().split())))
    for j in range(n):
        if array[i][j] != 0:
            virus.append((array[i][j],0,i,j))

virus.sort()
queue = deque(virus)

# s초 후에 (x,y) 위치에 바이러스 
s,x,y = map(int,input().split())

# 상하좌우
dx = [0,0,-1,1]
dy = [-1,1,0,0]

while queue:
    v,time,nowx,nowy = queue.popleft()
    if time == s:
        break
    for i in range(4):
        nx,ny = nowx+dx[i], nowy+dy[i]
        if nx>=0 and ny<n and nx<n and ny>=0 and array[nx][ny] == 0:
            array[nx][ny] = v
            queue.append((v,time+1,nx,ny))
    
print(array[x-1][y-1])