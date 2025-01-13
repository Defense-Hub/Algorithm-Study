import sys
input = sys.stdin.readline

n, m = map(int, input().split())
array = list(map(int, input().split())) 

def solution():
    cnt = 0
    answer = 0

    rest = [0] * m # m으로 나눈 나머지 담는 곳
    for i in range(n):
        cnt += array[i]
        rest[cnt % m] += 1

    answer = rest[0] # 나머지가 0이 되는 경우의 수
    for i in range(m):
        # nC2 = n(n-1)/2 공식 사용
        answer += rest[i] * (rest[i]-1) // 2

    print(answer)

solution()