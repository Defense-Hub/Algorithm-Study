import sys

input = sys.stdin.readline
n,m = map(int,input().split())

array = [int(input()) for _ in range(n)]
# 먼저 배열을 정렬해준다
array.sort()

answer = int(1e9)
start = 0
end = 0

while end < n:
    value = array[end] - array[start]
    if value > m:
        answer = min(answer,array[end] - array[start])
        start += 1
    elif value < m:
        end += 1
    # 차이가 m인 경우가 발생했을 경우, m보다 작은 차이가 나는 경우는 없으므로 리턴
    else:
        answer = m
        break
        

print(answer)