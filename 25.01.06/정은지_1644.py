import math
import sys
input = sys.stdin.readline

n = int(input())
prime_num_array = []
prime_num = [True] * (n + 1)

# 소수 배열 구하기
def get_prime_number():
    for i in range(2, int(math.sqrt(n)+1)): # 에라토스테네스의 채
        if prime_num[i] == True:
            j = 2
            while (i * j) <= n:
                prime_num[i*j] = False
                j += 1
    
    for i in range(2,n+1):
        if prime_num[i]:
            prime_num_array.append(i)

def solution():
    answer = 0
    get_prime_number()
    start = 0
    end = 0
    num = prime_num_array[0]

    # 투포인터
    while end <= len(prime_num_array):
        if num > n:
            num -= prime_num_array[start]
            start+=1
        else:
            if num == n:
                answer += 1
            end += 1
            if end == len(prime_num_array):
                break
            num += prime_num_array[end]

    return answer

if n == 1:
    print(0)
else:
    print(solution())