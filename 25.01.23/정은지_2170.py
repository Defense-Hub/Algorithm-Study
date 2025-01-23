import sys
input = sys.stdin.readline

n = int(input())
array = []

# 투포인터
def draw_line():
    answer = 0
    start, end = array[0][0], array[0][1]

    for i in range(1, n):
        row, col = array[i]
        if row > end: # 선이 이어지지 않는 경우 (정렬 했으므로)
            answer += end-start
            start, end = row, col
        elif col > end: # 겹치는 경우
            end = col
        else: # 현재 그려진 선에 포함되는 경우
            continue

    answer += (end-start)
    print(answer)

def solution():
    for _ in range(n):
        row, col = map(int,input().split())
        array.append((row, col))

    array.sort()
    draw_line()
    
solution()