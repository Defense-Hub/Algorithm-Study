# 17:28 ~ 18:00

def collatx(k):
    idx = 0
    array = [k]
     
    while(k!=1):
        idx +=1
        if k%2 ==1:
            k = k*3 + 1
        else:
            k //= 2            
        array.append(k)  
        
    return array

def definite_integral(points,a,b):
    b += len(points)
    print(a,b)
        
    if b<=a:
        return -1
    
    total_area = 0
    for i in range(a,b-1):
        total_area += (points[i]+points[i+1])/2

    return total_area
    
def solution(k, ranges):
    answer = []
    points = collatx(k)
    
    for a,b in ranges:
        answer.append(definite_integral(points,a,b))

    return answer

