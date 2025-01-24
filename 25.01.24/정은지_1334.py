import sys
input = sys.stdin.readline

n = input().strip() # 하 공백제거때문에 한시간씀
length = len(n)
half_n = n[:(length + 1) // 2]

def solution():
    global n

    # 9 or 99 or 999 or 9999 ... 이런 경우면
    if n == "9" * length:
        print(int(n) + 2)
    elif length == 1: # 한자리수인 경우
        print(int(n) + 1)
    # 만약 숫자의 길이가 홀수인 경우
    elif length % 2 != 0:
        temp = half_n + half_n[-2::-1]
        if int(temp) > int(n):
            print(temp)
        else:
            temp = str(int(half_n) + 1)
            temp = temp[:] + temp[-2::-1]
            print(temp)
    # 만약 숫자의 길이가 짝수인 경우
    else:
        temp = half_n + half_n[::-1]
        if int(temp) > int(n):
            print(temp)
        else:
            temp = str(int(half_n) + 1)
            temp = temp[:] + temp[::-1]
            print(temp)

solution()



