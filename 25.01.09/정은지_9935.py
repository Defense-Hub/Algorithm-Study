import sys
input = sys.stdin.readline

str = input().strip()
explosion_str = input().strip()

def check_explosion(str):
    stack = []

    for i in str:
        stack.append(i)
        # 스택의 마지막 explosion_str 길이만큼의 문자열이 explosion_str과 같은 경우
        if "".join(stack[-len(explosion_str):]) == explosion_str:
            for _ in range(len(explosion_str)):
                stack.pop()

    return "".join(stack)

def solution():
    global str
    str = check_explosion(str)
    
    if str != '':
        print(str)
    else:
        print("FRULA")

solution()