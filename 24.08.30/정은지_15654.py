from itertools import permutations
import sys
input = sys.stdin.readline

n,m = map(int,input().split())
array = list(map(int,input().split()))

permus = list(permutations(array,m))
permus.sort()

for permu in permus:
    for i in permu:
        print(i,end=" ")
    print()