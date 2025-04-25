# 16:10 ~ 17:26

import pprint
from collections import deque

def update_accessible_container(x,y):
    global n,m, accessible_container,visited
    queue = deque([(x,y)])

    while(queue):
        cur_x, cur_y = queue.popleft()
        for dx, dy in [(-1,0),(1,0),(0,-1),(0,1)]:
            nx, ny = cur_x+dx, cur_y+dy
            if 0 <= nx < n and 0 <= ny < m and not accessible_container[nx][ny]:
                accessible_container[nx][ny] = True
                if visited[nx][ny]: # 만약 이전에 접근했던 칸인 경우, 'bb'와 같이 그냥 뽑은 칸이라 접근 가능한지 처리가 안되어있을 수 있다.
                    queue.append((nx,ny))

    
def bfs(request):
    global matrix,n,m, accessible_container,visited
    
    # 요청된 종류의 모든 컨테이너 꺼내기
    if len(request) == 2:
        for i in range(n):
            for j in range(m):
                if matrix[i][j] == request[0] and not visited[i][j]:
                    visited[i][j] = True
                    if accessible_container[i][j]: # 접근 가능한 컨테이너가 출고된 경우
                        update_accessible_container(i,j)            
        return
    
    # 접근 가능한 컨테이너만 출고하기
    visited_position = []
    for i in range(n):
        for j in range(m):
            if matrix[i][j] == request and accessible_container[i][j] and not visited[i][j]:
                visited_position.append((i,j)) # 현재 상태 업데이트 되면 안되므로 미리 저장
                
    for i,j in visited_position:
        update_accessible_container(i,j)
        visited[i][j] = True

def solution(storage, requests):
    global matrix,n,m, accessible_container,visited
    
    matrix = [list(i) for i in storage]
    n = len(matrix)
    m = len(matrix[0])
    
    visited = [[False]* m for _ in range(n)] 
    accessible_container = [[False]* m for _ in range(n)]
    
    # 현재 접근 가능한 맨 끝줄 컨테이너들 업데이트
    for i in range(n):
        for j in range(m):
            if i == 0 or i == n-1 or j==0 or j==m-1:
                accessible_container[i][j] = True
    
    for request in requests:
        bfs(request)

    return sum(not i for row in visited for i in row)

# solution(["AAAAA", "ABCDA", "AGAEA", "AZAFA", "ZYAAA"], ["BB", "DD", "Z", "Y", "Z", "G", "C", "E", "F"]) # 16 반례
# solution(["AZWQY", "CAABX", "BBDDA", "ACACA"], ["A", "BB", "A"]) # 11
# solution(["HAH", "HBH", "HHH", "HAH", "HBH"], ["C", "B", "B", "B", "B", "H"])