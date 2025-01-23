import sys
input = sys.stdin.readline

n,k = map(int,input().split())
coins = list(int(input()) for _ in range(n))
dp = [int(1e9)] * 10001
dp[0] = 0

def solution():
    for coin in coins:
        for i in range(coin, k+1): # 현재 갖고 있는 동전 i를 기준으로 i 미만의 값은 갱신될리 없으므로 i부터 시작
            # 점화식 .. .
            dp[i] = min(dp[i],dp[i-coin]+1)
    
    if dp[k] == int(1e9):
        print(-1)
    else:
        print(dp[k])

solution()