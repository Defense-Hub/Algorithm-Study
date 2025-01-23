import sys
input = sys.stdin.readline

s = input().strip()
t = input().strip()

# 역으로 t -> s 로 바꿔보기
# 1. 뒤에 A가 있으면 지우기. 길이가 같다면 비교하기
# 2. 뒤에 B가 있으면 지우고 뒤집기. 길이가 같다면 비교하기

def check_str():
    global t
    if t[-1] == 'A':
        t = t[:-1]
        # print("A 변환",t)
    elif t[-1] == 'B':
        t = t[:-1]
        t = t[::-1]
        # print("B 변환",t)

def solution():
    while(True):
        if len(s) == len(t):
            break
        check_str()
    
    if s == t:
        print(1)
    else:
        print(0)
solution()