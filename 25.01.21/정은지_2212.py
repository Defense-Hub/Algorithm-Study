import sys
input = sys.stdin.readline

n = int(input())
k = int(input())

def solution():
    pos = list(map(int, input().split()))
    pos.sort()

    array = []
    for i in range(1, n):
        array.append(pos[i] - pos[i-1]) # 센서 간 차이

    array.sort()
  
    print(sum(array[:n-k])) # 가장 긴것 K-1개를 제외한 나머지의 합

solution()
