# 16:04~16:40

import sys
from collections import deque
input = sys.stdin.readline

n,k = map(int,input().split())
MAX = 100001
visited = [-1] * MAX
route = [-1] * MAX

def track(start,end):
    path = []
    while end != start:
        path.append(end)
        end = route[end]
    path.append(start)
    print(len(path) - 1)
    print(" ".join(map(str, path[::-1])))  

def bfs():
    queue = deque([n])

    while(queue):
        curPos = queue.popleft()
        if curPos == k:
            track(n,k)
            return
        for nextPos in (curPos+1, curPos-1, curPos*2):
            if 0 <= nextPos< MAX and visited[nextPos]==-1:
                visited[nextPos] = visited[curPos]+1
                route[nextPos] = curPos
                queue.append(nextPos)
                
def solution():
    visited[n] = 0
    route[n] = n

    bfs()

solution()