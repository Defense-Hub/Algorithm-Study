import sys
input = sys.stdin.readline

def solution():
    n = int(input())
    array = list(map(int, input().split()))
    s = int(input())
    for i in range(n-1):
        if s == 0:
            break
        mx, idx = array[i], i
        for j in range(i+1, min(n, i+1+s)):
            if mx < array[j]:
                mx = array[j]
                idx = j
        s -= idx-i
        for j in range(idx, i, -1):
            array[j] = array[j-1]
        array[i] = mx
    print(*array)

solution()