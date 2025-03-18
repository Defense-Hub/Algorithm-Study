# 16:40 ~ 17:27

import sys
input = sys.stdin.readline

n = int(input())
m = int(input())
if m != 0 :
    array = list(map(int,input().split()))
answer = abs(n - 100) # 0으로 설정하면 틀림. 100 채널부터 시작하므로 최소 경우의 수는 0이 아니기 때문이다

def find_min_press_count():
    global answer
    buttons = list(i for i in range(10) if i not in array)

    # 목표 채널을 눌러서 목표 값을 만들기 위한 최소 버튼 클릭 횟수 계산
    min_clicks = abs(n - 100)

    for i in range(1000000):  # 충분히 큰 범위 (최대 999999까지)
        str_i = str(i)
        is_valid = True
        for digit in str_i:
            if int(digit) not in buttons:
                is_valid = False
                break

        if is_valid:
            # 목표 채널과의 차이를 구한 후, 최소 클릭 횟수 업데이트
            min_clicks = min(min_clicks, len(str_i) + abs(n - i))

    answer = min_clicks

def solution():
    global answer

    if m == 0:
        answer = min(answer,len(list(str(n))))
    elif n == 100:
        answer = 0
    else:
        find_min_press_count()

    print(answer)

solution()