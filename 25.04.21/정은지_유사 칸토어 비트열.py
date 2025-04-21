# 17:09 ~ 17:44

def is_one(index):
    while index >= 5:
        if (index - 2) % 5 == 0:
            return False
        index //= 5

    return index != 2


def solution(n, l, r):
    answer = 0
    for i in range(l-1,r):
        if is_one(i):
            answer += 1
        
    return answer

solution(2,4,17)