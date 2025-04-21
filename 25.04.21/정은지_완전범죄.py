# 18:01 ~ 18:46

def solution(info, n, m):
    dic = {0:0}
    for x,y in info:
        now_check = {}
        for xx,yy in dic.items():
            if xx + x < n:
                if xx + x not in now_check or now_check[xx+x] > yy:
                    now_check[xx+x] = yy
            if yy + y < m:
                if xx not in now_check or now_check[xx]> yy + y:
                    now_check[xx] = yy+y
        
        if now_check:
            dic = now_check
        else: # a,b 둘 다에게 흔적을 남기지 못한 경우
            return -1
    return min(dic.keys())

solution([[1, 2], [2, 3], [2, 1]],4,4) #2
#solution([[3, 3], [3, 3]], 6, 1)