# 12:48 ~ 13:08

import sys
input = sys.stdin.readline

t = int(input())

def kaing_calendar(m, n, x, y):
    k = x
    while(k <= m*n):
        if (k-x)%m == 0 and (k-y)%n == 0:
            return k
        k+=m        
    return -1

def solution():
    for _ in range(t):
        m, n, x, y = map(int, input().split())
        print(kaing_calendar(m, n, x, y))

solution()