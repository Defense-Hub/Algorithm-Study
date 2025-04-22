# 15:48 ~ 16:25

import heapq

def mix():
    global heap
    
    fir = heapq.heappop(heap)
    sec = heapq.heappop(heap)
    
    heapq.heappush(heap, fir + 2*sec)  

def solution(scoville, K):
    global heap
    answer = 0
    heap = []
    for i in scoville:
        heapq.heappush(heap, i)

    while(heap[0] < K):      
        if len(heap) < 2:
            answer = -1
            break
        mix()
        answer += 1
    
    return answer