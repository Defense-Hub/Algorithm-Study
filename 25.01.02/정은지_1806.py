import sys
input = sys.stdin.readline

n,s = map(int,input().split())
array = list(map(int,input().split()))

def solution():
    answer = int(1e9) # 최소 길이
    left = 0
    right = 0
    sum = 0

    while(True):
        if sum >= s:
            answer = min(answer, right-left)
            sum -= array[left]
            left += 1
        elif right == n:
            break
        else:
            sum += array[right]
            right += 1
    
    if answer == int(1e9):
        answer = 0

    return answer

print(solution())