import sys
input = sys.stdin.readline
n,k = map(int,input().split())
mod = 1000000007

def factorial(n):
    num = 1
    for i in range(2, n+1):
        num = (num * i) % mod
    return num

def square(n, k):
    if k == 0:
        return 1
    elif k == 1:
        return n
    
    tmp = square(n, k//2)
    if k % 2:
        return tmp * tmp * n % mod
    else:
        return tmp * tmp % mod

top = factorial(n)
bot = factorial(n-k) * factorial(k) % mod

# 페르마의 소정리.. 
print(top * square(bot, mod-2) % mod)