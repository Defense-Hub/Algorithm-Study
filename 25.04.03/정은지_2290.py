# 16:32 ~ 17:51

import sys
input = sys.stdin.readline

s, n = map(int, input().split())
n = list(str(n))
hor_len = (s+3) * len(n) - 1  # 숫자 간 공백 포함
ver_len = 2 * s + 3
lcd = [[" " for _ in range(hor_len)] for _ in range(ver_len)]

def segment(idx, parts):
    start = (s+3) * idx 
    for part in parts:
        if part == 1:
            for i in range(start + 1, start + s + 1):
                lcd[0][i] = '-'
        if part == 2:
            for i in range(start + 1, start + s + 1):
                lcd[ver_len // 2][i] = '-'
        if part == 3:
            for i in range(start + 1, start + s + 1):
                lcd[ver_len - 1][i] = '-'
        if part == 4:
            for i in range(1, s + 1):
                lcd[i][start] = "|"
        if part == 5:
            for i in range(s + 2, 2 * s + 2):
                lcd[i][start] = "|"
        if part == 6:
            for i in range(1, s + 1):
                lcd[i][start + s + 1] = "|"
        if part == 7:
            for i in range(s + 2, 2 * s + 2):
                lcd[i][start + s + 1] = "|"

def lcd_number(number, idx):
    if number == 1:
        segment(idx, [6,7])
    if number == 2:
        segment(idx, [1,2,3,5,6])
    if number == 3:
        segment(idx, [1,2,3,6,7])
    if number == 4:
        segment(idx, [2,4,6,7])
    if number == 5:
        segment(idx, [1,2,3,4,7])
    if number == 6:
        segment(idx, [1,2,3,4,5,7])
    if number == 7:
        segment(idx, [1,6,7])
    if number == 8:
        segment(idx, [1,2,3,4,5,6,7])
    if number == 9:
        segment(idx, [1,2,3,4,6,7])
    if number == 0:
        segment(idx, [1,3,4,5,6,7])

def solution():
    for idx, i in enumerate(n):
        lcd_number(int(i), idx)

    for row in lcd:
        print("".join(row))

solution()
