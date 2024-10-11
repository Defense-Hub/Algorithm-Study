def is_prime_number(num):
    num = int(num)
        
    if num < 2:  
        return False

    for i in range(2, int(num**(1/2)) +1 ):
        if num % i == 0:
            return False 
    return True

def k_number(n,k):
    string = ''
    while n>0:
        string += str(n%k)
        n //= k       
    return string[::-1]

def solution(n, k):
    answer = 0
    k_num = k_number(n, k)
    nums = str(k_num).split('0')

    for num in nums:
        if num and is_prime_number(num):
            answer+=1
    return answer