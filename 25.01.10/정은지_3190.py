import sys
input = sys.stdin.readline
from collections import deque

n = int(input())
k = int(input())

graph = [[0] * n for _ in range(n)]
dx = [0, 1, 0, -1]
dy = [1, 0, -1, 0]

for i in range(k):
    x, y = map(int, input().split())
    graph[x - 1][y - 1] = 2

l = int(input())
dictionary = dict()
queue = deque()
queue.append((0, 0))

for i in range(l):
    x, c = input().split()
    dictionary[int(x)] = c

x, y = 0, 0
graph[x][y] = 1
cnt = 0
direction = 0

def snake_turn(alpha):
    global direction
    if alpha == 'L':
        direction = (direction - 1) % 4
    else:
        direction = (direction + 1) % 4


while True:
    cnt += 1
    x += dx[direction]
    y += dy[direction]

    if x < 0 or x >= n or y < 0 or y >= n:
        break

    if graph[x][y] == 2:
        graph[x][y] = 1
        queue.append((x, y))
        if cnt in dictionary:
            snake_turn(dictionary[cnt])

    elif graph[x][y] == 0:
        graph[x][y] = 1
        queue.append((x, y))
        tx, ty = queue.popleft()
        graph[tx][ty] = 0
        if cnt in dictionary:
            snake_turn(dictionary[cnt])

    else:
        break

print(cnt)