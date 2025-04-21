# 17:09 ~ 17:40

def is_one(index,n):
    while(n > 0):
        length = 5 ** (n-1)
        section = index // length
        
        if section == 2:
            return False  
        
        index %= length
        n-=1
    
    return True

def solution(n, l, r):
    answer = 0
    for i in range(l-1,r):
        if is_one(i,n):
            answer += 1
        
    return answer

solution(2,4,17)