def solution(m, n, puddles):
    # x,y 뒤집어야함
    dp = [[0 for _ in range(m)] for _ in range(n)]
    dp[0][0] = 1
    
    p = []
    for puddle in puddles:
        x,y = puddle
        p.append([y-1,x-1])
        
    for i in range(n):
        for j in range(m):
            if i==0 and j==0:
                continue
            
            if [i,j] in p: 
                dp[i][j] = 0
            else:
                dp[i][j] = (dp[i-1][j] + dp[i][j-1])%1000000007
    
    return dp[n-1][m-1]