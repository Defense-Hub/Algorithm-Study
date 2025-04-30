# 14:20 ~ 14:58

def max_proper_divisor(number):
    if number == 1:
        return 1
    
    num = 1
    for i in range(2,int(number ** 0.5)+1):
        if number % i ==0:
            # 약수 두 개가 범위 내의 숫자인지 확인했어야함
            if i <= 10_000_000:
                num = max(num,i)
            if number//i <= 10_000_000:
                num = max(num,number//i)          
    return num

def solution(begin, end):
    answer = []
    
    for i in range(begin,end+1):
        if i == 1:
            answer.append(0) 
        else:
            divisor = max_proper_divisor(i)
            answer.append(divisor)
    
    return answer