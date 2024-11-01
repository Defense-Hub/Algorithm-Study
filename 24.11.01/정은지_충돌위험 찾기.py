from collections import defaultdict
from collections import Counter
import copy

def solution(points, routes):
    answer = 0
    
    # 위치 좌표 딕셔너리 선언
    positions = defaultdict(list)
    for i in range(len(points)):
        positions[i+1] = points[i]
    
    # key = 로봇의 번호, value = [현재 위치, (로봇의 경로들,이미 지나간 경로인지), 로봇의 목적지 도착 여부]
    robot_route = defaultdict(list)
    for i in range(len(routes)):
        robot_route[i+1].append(positions[routes[i][0]].copy())
        for j in routes[i][1:]:
            lst = positions[j].copy()
            lst.append(False)
            robot_route[i+1].append(lst)
        robot_route[i+1].append(False)
    
    fir = []
    # 시작할 때 같은 위치에서 시작하는지 검사
    for i in robot_route:
        fir.append(tuple(robot_route[i][0]))

    for item,cnt in Counter(fir).items():
        if cnt >= 2:
            answer+=1
            
    #경로 탐색
    arrive_cnt = 0
    while True:
        now_positions = []
        # 모든 로봇이 목적지에 도착했을 경우 while문 break
        if arrive_cnt == len(routes):
            break
        
        for i in range(1,len(robot_route)+1):
            # 이미 목적지에 도착한 로봇인 경우 continue
            if robot_route[i][-1]:
                continue
                
            # i번 로봇의 시작위치
            nx,ny = robot_route[i][0]
            
            now_destination_idx = -1
            # i번 로봇의 목적지
            for idx,destination in enumerate(robot_route[i][1:-1]):
                if not destination[2]:
                    dx,dy = destination[0], destination[1]
                    now_destination_idx = idx+1
                    break
                
            # x좌표 움직일 수 있을 때
            if abs(nx-dx) >= 1:
                if nx>dx:
                    robot_route[i][0][0] -= 1                    
                else:
                    robot_route[i][0][0] += 1
            elif abs(ny-dy) >= 1:
                if ny>dy:
                    robot_route[i][0][1] -= 1
                else:
                    robot_route[i][0][1] += 1
                    
            now_positions.append(tuple(robot_route[i][0]))
            
            # 현재 설정된 목적지 도착시
            if robot_route[i][0][0]==dx and robot_route[i][0][1]==dy:  
                robot_route[i][now_destination_idx][2] = True
                
                # 마지막 목적지 도착시
                if now_destination_idx == len(robot_route[i])-2:
                    robot_route[i][-1] = True
                    arrive_cnt += 1
                
        # print(robot_route)               

        # 현재 로봇들의 위치 리스트 now_positions 검사
        counter = Counter(now_positions)

        for item,count in counter.items():
            if count >= 2:
                answer += 1
    return answer
