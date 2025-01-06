import bisect
import sys
input = sys.stdin.readline

t = int(input())
n = int(input())
array1 = list(map(int,input().split()))
m = int(input())
array2 = list(map(int,input().split()))

sum1 = [] # array1의 누적합 
sum2 = [] # array2의 누적합
answer = 0

for i in range(n):  
    s = array1[i]
    sum1.append(s)
    for j in range(i+1, n):
        s += array1[j]
        sum1.append(s)

for i in range(m): 
    s = array2[i]
    sum2.append(s)
    for j in range(i+1, m):
        s += array2[j]
        sum2.append(s)

sum1.sort()
sum2.sort()

for i in range(len(sum1)):
    l = bisect.bisect_left(sum2,t-sum1[i])
    r = bisect.bisect_right(sum2,t-sum1[i])
    answer += r-l
print(answer)
