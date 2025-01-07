import sys
input = sys.stdin.readline
n = int(input())
mod = 1000000
period = mod // 10*15 # 피사노주기
fibonacci = [0,1]

def get_fibonacci():
    for i in range(2,period):
        fibonacci.append((fibonacci[i-1]+fibonacci[i-2])%mod)

def solution():
    get_fibonacci()

    return fibonacci[n % period] # 실제 결과값을 mod로 나누는 것이 아닌 n을 mod로 나누기

print(solution())