n = int(input())
array = []
dp = [1] * (n+1)

def solution():
    for i in range(n):
        a, b = map(int, input().split())
        array.append([a, b])

    array.sort() # a가 작은 순서대로 정렬

    for i in range(1, n):
        for j in range(0, i):
            if array[j][1] < array[i][1]: # 앞순서의 b가 뒷순서의 b보다 작은 경우가 최대로 이어지는 경우
            dp[i] = max(dp[i], dp[j]+1)
        
    print(n - max(dp))

solution()