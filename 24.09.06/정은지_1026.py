n = int(input())
aLst = list(map(int,input().split()))
bLst = list(map(int,input().split()))

aLst.sort()
s = 0
for i in range(n):
    s += aLst[i] * max(bLst)
    bLst.remove(max(bLst))

print(s)