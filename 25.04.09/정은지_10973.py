# 15:01 ~ 15:10

import sys
input = sys.stdin.readline

n = int(input())
permutation = list(map(int,input().split()))

def solution(): 
    i = n-2
    while i >= 0 and permutation[i] <= permutation[i+1]:
        i -= 1

    if i == -1: # i가 n-2 ~ 0일때까지 앞의 수가 더 작았다는 것은 오름차순이라는 말
        print(-1)
        return

    j = n-1
    while permutation[i] <= permutation[j]:
        j -= 1

    permutation[i], permutation[j] = permutation[j], permutation[i]
    permutation[i + 1:] = sorted(permutation[i + 1:],reverse = True)

    print(*permutation)

solution()