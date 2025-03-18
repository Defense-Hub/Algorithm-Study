# 15:36 ~ 16:14
 
import sys
input = sys.stdin.readline

n = int(input())
board = [list(input().strip()) for _ in range(n)]

visited = [[False] * n for _ in range(n)]
dx = [0,0,1,-1] 
dy = [1,-1,-0,0]
answer = 0

# board에서 사탕의 색이 다른 인접한 두 칸 찾고 바꾸는 메서드
def exchange_different_color_candy(i,j):
    global answer

    for k in range(4):
        nx,ny = i+dx[k], j+dy[k]
        if 0<=nx<n and 0<=ny<n and not visited[nx][ny] and board[i][j] != board[nx][ny]:
            board[i][j],board[nx][ny] = board[nx][ny], board[i][j]
            answer = max(answer,find_max_candy_cnt(board))
            board[nx][ny], board[i][j] = board[i][j],board[nx][ny]


# board에서 가장 긴 연속하는 알파벳의 길이 구하는 메서드
def find_max_candy_cnt(board):
    cnt = 0

    for i in range(n):        
        hor_list = board[i]
        ver_list = []
        for j in range(n):
            ver_list.append(board[j][i])
            
        cnt = max(cnt, check_line(hor_list), check_line(ver_list))
    return cnt

# 한 줄의 array에서 가장 긴 연속하는 알파벳의 길이 구하는 메서드
def check_line(array):
    cnt = 0
    dp = [0] * n
    dp[0] = 1

    for i in range(1,n):
        if array[i] == array[i-1]:
            dp[i] = dp[i-1]+1
        else:
            cnt = max(cnt, dp[i])
            dp[i] = 1
    
    return max(cnt, max(dp))


def solution():
    for i in range(n):
        for j in range(n):
            visited[i][j] = True
            exchange_different_color_candy(i,j)
            visited[i][j] = False
    print(answer)

solution()