from collections import deque
import sys
input = sys.stdin.readline

#동서남북 상 하
dx = [1, -1, 0, 0, 0, 0]
dy = [0, 0, 1, -1, 0, 0]
dz = [0, 0, 0, 0, 1, -1]

while True:
    # 층 행 열
    l,r,c = map(int,input().split())
    # 종료 조건
    if l==0 and r==0 and c==0:
        break

    # 빌딩 배열
    array = [] 
    # 방문 체크 
    visited = [[[False] * c for _ in range(r)] for _ in range(l)]
    # 탈출 가능 여부
    canEscape = False

    queue = deque()

    for _ in range(l):
        building = []
        for _ in range(r):
            building.append(list(input().strip()))
        array.append(building)
        # 빈 줄 처리
        input()  

    for height in range(l):
        for i in range(r):
            for j in range(c):
                if array[height][i][j] == "S":
                    # 시작지점
                    queue.append((height,i,j,0))
                if array[height][i][j] == "E":
                    # 목적지 저장
                    goal = (height,i,j)
                
    while queue:
        h,x,y,t = queue.popleft()
        if goal == (h,x,y):
            canEscape = True
            print(f'Escaped in {t} minute(s).')
            break

        for i in range(6):
            nx = x + dx[i]
            ny = y + dy[i]
            nz = h + dz[i]

            # 이동 좌표가 범위 내에 있을 때
            if nx>=0 and nx<r and ny>=0 and ny<c and nz>=0 and nz<l:
                if not visited[nz][nx][ny] and (array[nz][nx][ny] == "." or array[nz][nx][ny] == "E"):
                    visited[nz][nx][ny] = True
                    queue.append((nz,nx,ny,t+1))  

    if not canEscape:
        print("Trapped!")
