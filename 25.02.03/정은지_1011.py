t = int(input())

for _ in range(t):
    x, y = map(int, input().split())
    
    distance = y - x # y와 x 사이의 거리
    tmp = 0 # 이동 거리
    cnt = 0 # 공간 장치 이동 횟수
    moving = 0 # 반복 횟수

    while tmp < distance:
        cnt += 1
        if cnt % 2 != 0:
            moving += 1
        tmp += moving
        
    print(cnt)