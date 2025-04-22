# 14:57 ~ 15:38

def solution(n):
    dp = [0] * (n+1)
    dp[0] = 1
    dp[2] = 3
    
    # n이 짝수일때만 성립
    for i in range(4,n+1,2):
        dp[i] = dp[i-2] * 3 + 2
        for j in range(4,i,2):
            dp[i] += dp[i-j]*2
    
    return dp[n] % 1000000007