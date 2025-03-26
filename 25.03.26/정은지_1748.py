# 13:19 ~
# dp??

import sys
input = sys.stdin.readline

n = int(input())
length = len(str(n))

def solution():
    answer = 0
    for i in range(1,length):
        answer += 9 * 10 ** (i-1) * i
    answer += (n - 10**(length-1)+1) * length
    print(answer)

solution()