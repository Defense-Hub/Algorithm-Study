def check_distance(m,n,startX,startY,endX,endY):
    distances = []
    # 공을 벽 너머 좌표로 대칭이동 후 그 좌표와 목표지점과의 거리 구하기
    
    # 위쪽 벽에 맞는 경우
    if startY > endY or startX != endX:
        distances.append((endX-startX)**2 + (endY-2*n+startY)**2)
    # 아래쪽 벽에 맞는 경우
    if startY < endY or startX != endX:
        distances.append((endX-startX)**2 + (endY+startY)**2)
    # 왼쪽 벽에 맞는 경우
    if startY != endY or startX < endX:
        distances.append((endX+startX)**2 + (endY-startY)**2)
    # 오른쪽 벽에 맞는 경우
    if startY != endY or startX > endX:
        distances.append((endX-2*m+startX)**2 + (endY-startY)**2)
    
    return min(distances)

def solution(m, n, startX, startY, balls):
    answer = []

    for ball_x, ball_y in balls:
        distance = check_distance(m,n,startX,startY,ball_x,ball_y)
        answer.append(distance)
    
    return answer