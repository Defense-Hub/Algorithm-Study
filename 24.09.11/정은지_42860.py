def solution(name):
    # 상하 이동 횟수
    updown = 0    
    # 좌우 이동 횟수 = 이름의 길이 - 1
    leftright = len(name) - 1  
       
    for idx, string in enumerate(name):
    	# 위아래 중 최소 이동 값
        updown += min(ord(string) - ord('A'), ord('Z') - ord(string) + 1)
        
        # 해당 알파벳 다음부터 연속된 A 문자열 찾기
        next = idx + 1
        while next < len(name) and name[next] == 'A':
            next += 1
            
        # 아래 3가지 경우 중 최소 이동 값으로 갱신
        # 1. 이전 커서 이동 값 (초기값 - 이름의 길이 - 1)
        # 2. 연속된 A의 왼쪽 시작
        # 3. 연속된 A의 오른쪽 시작
        leftright = min([ leftright, 2 * idx + len(name) - next, idx + 2 * (len(name) - next) ])
        
    return updown + leftright