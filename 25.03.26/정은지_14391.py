# 14:35 ~ 15:35

# 비트마스킹
# and(&) : 두 비트 다 1이면 1, or(|) : 두 비트 중 하나라도 1이면 1
# xor(^) : 두 비트 다르면 1, not(~) : 1이면 0, 0이면 1
# << or >> : 오른쪽 수 만큼 shift

import sys
input = sys.stdin.readline

n,m = map(int,input().split())
array = list(list(input().strip()) for _ in range(n))
answer = []

# 잘라진 종이의 수의 합이 최댓값이 나오는지 확인하려면 모든 경우의 수를 다 계산해야함 => 2^n*m가지 수로 매우 많은 경우의 수
# 1. 가로로 숫자를 읽으면서 가로로 이어지는 경우 계산
# 2. 세로로 숫자를 읽으면서 세로로 이어지는 경우 계산
# 3. 최대 합 계산

# for i in range(1<<n*m) 이건 2차원 배열을 한 줄로 늘어놓은 후 이진수대로 검사하기 위한 것이다.
# 예를 들어 i가 5, n=2, m=2면 i= 0101로 간주하여 첫번째 행을 [0,1] 두번째 행을[0,1]으로 두고, 이를 바탕으로 검사하는 것

def solution():
    # 원소가 가로로 이어지면 1, 세로로 이어지면 0이라고 가정
    for i in range(1<<n*m): # 1<<n*m == 2^n*m
        total_sum = 0
        for row in range(n): # 가로 합 계산
            row_sum = 0
            for col in range(m):
                idx = row*m + col # 2차원 배열을 1차원 배열로 생각했을 때의 인덱스
                if i & (1<<idx) != 0 : # 인덱스 숫자가 1이므로 숫자를 이어붙임
                    row_sum = 10 * row_sum + int(array[row][col]) # 이전 숫자와 현재 번호 이어붙이기
                else: # 0이므로 숫자를 끊음 -> total_sum에 더하고 새로운 숫자 선언
                    total_sum += row_sum
                    row_sum = 0
            total_sum += row_sum

        for col in range(m): # 세로 합 계산
            col_sum = 0
            for row in range(n):
                idx = row*m + col 
                if i & (1<<idx) == 0 : # 인덱스 숫자가 0이므로 숫자를 이어붙임
                    col_sum = 10 * col_sum + int(array[row][col])
                else: # 1이므로 숫자를 끊음 
                    total_sum += col_sum
                    col_sum = 0
            total_sum += col_sum
        
        answer.append(total_sum)
    print(max(answer))

solution()