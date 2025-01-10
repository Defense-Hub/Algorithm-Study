import heapq
import sys
from collections import defaultdict

input = sys.stdin.readline

minHeap = []
maxHeap = []
solved = defaultdict(int)
n = int(input())

for _ in range(n):
    p, l = map(int, input().split())
    heapq.heappush(minHeap, (l, p))
    heapq.heappush(maxHeap, (-l, -p))

m = int(input())
for _ in range(m):
    command = input().split()

    if command[0] == "recommend":
        # 어려운 문제 
        if command[1] == '1':
            while (solved[abs(maxHeap[0][1])] != 0):
                solved[abs(maxHeap[0][1])] -= 1
                heapq.heappop(maxHeap)
            print(-maxHeap[0][1])
        # 쉬운 문제 
        else:
            while (solved[minHeap[0][1]] != 0):
                solved[minHeap[0][1]] -= 1
                heapq.heappop(minHeap)
            print(minHeap[0][1])
    elif command[0] == "add":
        p = int(command[1])
        l = int(command[2])
        heapq.heappush(minHeap, (l, p))
        heapq.heappush(maxHeap, (-l, -p))
    elif command[0] == "solved":
        solved[int(command[1])] += 1