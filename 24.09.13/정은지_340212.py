def solution(diffs, times, limit):
    answer = 1
    left = 1
    right = max(diffs)
    
    while left <= right:
        mid = (left + right) // 2
        # 조건에 맞으면 더 작은 level값이 있는지 탐색
        if puzzle(mid,diffs,times,limit):
            right = mid - 1
            answer = mid
        # 조건에 맞지 않으면 level의 값 늘리기
        else:
            left = mid + 1
    return answer

def puzzle(level,diffs,times,limit):
    n = len(diffs)
    total_time = 0
    time_cur = 0
    time_prev = 0
    
    for i in range(n):
        time_cur = times[i]          
        # 1. diff > level이면 (diff-level)*(time_cur+time_prev)+time_cur
        if diffs[i] > level:
            total_time += (diffs[i]-level)*(time_cur+time_prev)+time_cur   
        # 2. diff <= level이면 time_cur만큼의 시간만 사용 
        else:
            total_time += time_cur
        time_prev = times[i]    
    
    return total_time <= limit