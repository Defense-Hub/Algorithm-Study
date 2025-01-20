import sys
input = sys.stdin.readline

n = int(input())
a = [*map(int, input().split())]

LIS = [a[0]]

def solution(e):
    start = 0
    end = len(LIS) - 1
    
    # 이분 탐색 .. (bisect 안쓰고 풀기)
    while start <= end:
        mid = (start + end) // 2
        
        if LIS[mid] == e:
            return mid
        elif LIS[mid] < e:
            start = mid + 1
        else:
            end = mid - 1
            
    return start

for item in a:
    if LIS[-1] < item:
        LIS.append(item)
    else:
        idx = solution(item)
        LIS[idx] = item

print(len(LIS))