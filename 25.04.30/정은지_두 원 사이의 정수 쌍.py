# 15:00 ~ 15:40

# 원점 사이의 거리를 구해서 나온 길이가 r1보다 길거나 같고 r2보다 작거나 같아야함
# 1사분면만 구하고 4 곱해도 됨
from math import sqrt 

def solution(r1, r2):
    answer = 0
    
    for i in range(0,r1):
        answer += int(sqrt(r2**2 - i**2)) - int(sqrt(r1**2 - i**2 - 1))
    
    for i in range(r1,r2):
        answer += int(sqrt(r2**2 - i**2))
        
    return answer*4

solution(1, 2)