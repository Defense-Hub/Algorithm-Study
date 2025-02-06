import sys
input = sys.stdin.readline

n, m = map(int, input().split())
k = int(input())

# 최단거리로 이동 => 항상 아래 혹은 오른쪽으로만 이동
def solution():
    maps = [[0] * (m + 2) for _ in range(n + 2)] 
    maps[1][1] = 1

    end = set()
    load = set()

    for _ in range(k):
        a, b, c, d = map(int, input().split())
        (a, b), (c, d) = sorted([(a + 1, b + 1), (c + 1, d + 1)]) # 시작 위치, 끝 위치를 정렬
        end.add((c, d)) # 공사 도로의 끝 지점
        load.add((a, b, c, d))  # 길을 저장해놔야 함

    for y in range(1, n + 2):
        for x in range(1, m + 2):
            if y == 1 and x == 1: # 시작 지점 제외
                continue

            if (y, x) in end: # 공사 도로의 끝 지점이라면
                if (y - 1, x, y, x) not in load: # 시작 지점을 빼고 더하기
                    maps[y][x] = maps[y - 1][x]
                elif (y, x - 1, y, x) not in load: # 시작 지점을 뺴고 더하기
                    maps[y][x] = maps[y][x - 1]
            else:
                maps[y][x] = maps[y - 1][x] + maps[y][x - 1]

    print(maps[n + 1][m + 1])

solution()