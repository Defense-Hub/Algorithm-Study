import sys
import math
input = sys.stdin.readline

n,m = map(int,input().split())
array = [list(input().strip()) for _ in range(n)]

def is_perfect_square_number(num):
    if int(math.sqrt(int(num))) ** 2 == int(num):
        return True
    else:
        return False
    
def solution():
    answer = -1
    for i in range(n):
        for j in range(m):
            for row_d in range(-n,n): # 행의 등차수열
                for col_d in range(-m,m): # 열의 등차수열
                    s = ""
                    x,y = i,j
                    if row_d == 0 and col_d == 0:
                        continue
                    while 0 <= x < n and 0 <= y < m:
                        s += array[x][y]
                        if is_perfect_square_number(s):
                            answer = max(answer,int(s))
                        x += row_d
                        y += col_d
    print(answer)

solution()