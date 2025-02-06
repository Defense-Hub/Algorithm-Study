import sys
input = sys.stdin.readline

n, m = map(int, input().split())
a_array = []
for _ in range(n):
    a_array.append(list(map(int, input().split())))

m, k = map(int, input().split())
b_array = []
for _ in range(m):
    b_array.append(list(map(int, input().split())))

def solution():
    c_array = [[0 for _ in range(k)] for _ in range(n)]

    for i in range(n):
        for j in range(k):
            for h in range(m):
                c_array[i][j] += a_array[i][h] * b_array[h][j]

    for i in c_array:
        for j in i:
            print(j, end = ' ')
        print()

solution()