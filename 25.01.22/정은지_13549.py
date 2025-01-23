import sys
input = sys.stdin.readline
from collections import deque

n,k = map(int,input().split())
length = 100001 # 문제 조건에서 최대 100,000이므로
array = [0] * length

def bfs():
    queue = deque()
    if n==0:
        queue.append(1)
    else:
        queue.append(n)

    while queue:
        x = queue.popleft()
        if k == x:
            return array[x]

        for nx in (x-1,x+1,x*2):
            if nx >= 0 and nx < length and array[nx] == 0:
                if nx == x*2:
                    array[nx] = array[x]
                    queue.appendleft(nx) # 다익스트라,,가중치가 0인 간선은 큐의 맨앞에 삽입
                else:
                    array[nx] = array[x]+1
                    queue.append(nx)


def solution():
    global n,k
    if n == 0:
        if k == 0:
            print(0)
        else:
            print(bfs()+1)
    else: 
        print(bfs())

solution()