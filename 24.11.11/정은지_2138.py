import sys
import copy
input = sys.stdin.readline

n = int(input())

now_bulbs = list(map(int,input().strip()))
goal_bulbs = list(map(int,input().strip()))

def press_switch(idx,bulbs):
    if idx-1 >=0:
        convert01(idx-1,bulbs)
    convert01(idx,bulbs)
    if idx+1 < n:
        convert01(idx+1,bulbs)

def convert01(idx,bulbs):
    if bulbs[idx] == 1:
        bulbs[idx] = 0
    else:
        bulbs[idx] = 1

def solution():
    answer = []
    n_bulbs = now_bulbs.copy()
    
    # 0번째 스위치 누르는 경우
    press_switch(0,n_bulbs)
    cnt = 1
    for i in range(1,n):
        # 왼쪽 전구가 존재 & 목표 전구와 다른 경우 반드시 누른다
        if i-1>=0 and n_bulbs[i-1] != goal_bulbs[i-1]:
            press_switch(i,n_bulbs)
            cnt += 1

    if n_bulbs == goal_bulbs:
        answer.append(cnt)

    cnt = 0
    # 0번째 스위치 누르지 않는 경우
    for i in range(1,n):
        if i-1>=0 and now_bulbs[i-1] != goal_bulbs[i-1]:
            press_switch(i,now_bulbs)
            cnt += 1
            
    if now_bulbs == goal_bulbs:
        answer.append(cnt)

    if answer:
        print(min(answer))
    else:
        print(-1)
solution()

# 전구를 누르는 순서는 상관이 없다
# 따라서 순차적으로 앞 인덱스부터 스위치를 누를지말지 결정한다.
# 이때 왼쪽의 전구가 goal_bulbs와 다른채로 넘어갈 수 없다 (다시 앞의 전구로 돌아가 바꿀 수 없기 때문)
# 경우의 수는 0번째 전구 누르기 or 누르지 않는 경우