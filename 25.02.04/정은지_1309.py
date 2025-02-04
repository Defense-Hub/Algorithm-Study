n = int(input())

# 사자가 없는 경우 3가지 수 아무거나 가능
# 사자가 있는 경우 빈 우리 or 반대 방향으로 배치
# 1. 현재 우리를 사자가 있는 우리와 없는 우리로 분리
# 2. 점화식 = 빈 우리의 수 × 3 + 사자가 있는 우리 × 2 

def solution():
    dp = [1,3] + [0]*(n-1)

    for i in range(2, n+1):
        dp[i] = (dp[i-2] + dp[i-1]*2) % 9901

    print(dp[n])

solution()

