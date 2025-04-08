import sys
input = sys.stdin.readline

n,m = map(int,input().split())
array = [list(map(int,input().split())) for _ in range(n)]

def solution():
    answer = n*m*2
     
    side1 = 0
    for i in range(n):
        for j in range(m):
            if j==0:
                side1 += array[i][j]
            else:
                if array[i][j] > array[i][j-1]:
                    side1 += array[i][j] - array[i][j-1]
    answer += side1*2

    side2 = 0
    for j in range(m):
        for i in range(n):
            if i==0:
                side2+= array[i][j]
            else:
                if array[i][j] > array[i-1][j]:
                    side2 += array[i][j] - array[i-1][j]
    answer += side2*2

    print(answer)    

solution()