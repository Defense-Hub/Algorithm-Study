# 15:35 ~ 16:26

import sys
input = sys.stdin.readline

n,m,x,y,k = map(int,input().split())
maps = [list(map(int,input().split())) for _ in range(n)]
commands = list(map(int, input().split()))
directions = [(0,1), (0,-1),(-1,0), (1,0)]
dice = [0,0,0,0,0,0]

def turn(dir):
    a, b, c, d, e, f = dice[0], dice[1], dice[2], dice[3], dice[4], dice[5]
    if dir == 1: # 동
        dice[0], dice[1], dice[2], dice[3], dice[4], dice[5] = d, b, a, f, e, c
    elif dir == 2: # 서
        dice[0], dice[1], dice[2], dice[3], dice[4], dice[5] = c, b, f, a, e, d
    elif dir == 3: # 북
        dice[0], dice[1], dice[2], dice[3], dice[4], dice[5] = e, a, c, d, f, b
    else: # 남
        dice[0], dice[1], dice[2], dice[3], dice[4], dice[5] = b, f, c, d, a, e

def move(dir):
    global x,y
    nx,ny = x+directions[dir-1][0], y+directions[dir-1][1]

    if 0<=nx<n and 0<=ny<m:
        turn(dir)
        
        if maps[nx][ny] == 0: # 이동한 칸에 쓰여있는 수가 0이면 주사위 바닥면에 쓰여있는 수가 칸에 복사
            maps[nx][ny] = dice[5]       
        else: # 0이 아닌 경우에는 칸에 쓰여 있는 수가 주사위의 바닥면으로 복사되며, 칸에 쓰여 있는 수는 0이 된다
            dice[5] = maps[nx][ny]
            maps[nx][ny] = 0

        print(dice[0])
        x,y = nx,ny


def solution():
    for command in commands:
        move(command)

solution()