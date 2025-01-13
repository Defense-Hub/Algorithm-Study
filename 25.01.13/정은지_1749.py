import sys
input = sys.stdin.readline

n, m = map(int, input().split())

array = []
for i in range(n):
    array.append(list(map(int, input().split())))

def solution():
    sum_array = [[0 for _ in range(m+1)] for _ in range(n+1)]

    # 누적 합 구하기
    for i in range(1, n+1):
        for j in range(1, m+1):
            sum_array[i][j] = sum_array[i][j-1] + array[i-1][j-1] + sum_array[i-1][j] - sum_array[i-1][j-1]


    answer = int(-10e9)

    for x1 in range(1, n+1):
        for y1 in range(1, m+1):
            for x2 in range(x1, n+1):
                for y2 in range(y1, m+1):
                    answer = max(answer, sum_array[x2][y2] - sum_array[x1-1][y2] - sum_array[x2][y1-1] + sum_array[x1 - 1][y1 - 1])

    print(answer)

solution()