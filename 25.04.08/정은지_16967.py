import sys
input = sys.stdin.readline

h,w,x,y = map(int,input().split())
array_b = [list(map(int,input().split())) for _ in range(h+x)]

def solution():
    array_a = [[0 for _ in range(w+y)] for _ in range(h+x)]

    for i in range(h+x):
        for j in range(w+y):
            val = array_b[i][j]
            if i < x: # 이동되지 않은 수
                array_a[i][j] = val
            elif j < y:
                array_a[i][j] = val
            else: # 이동된 수 
                array_a[i][j] = val - array_a[i-x][j-y]
    
    for i in range(h):
        for j in range(w):
            print(array_a[i][j],end=" ")
        print()

solution()