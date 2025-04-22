# 17:31 ~ 18:01

from collections import defaultdict
from collections import deque

def solution(msg):
    answer = []
    dic = defaultdict(int)
    alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
    index = 27
    
    # 길이가 1인 모든 단어를 포함하도록 사전을 초기화
    for idx,i in enumerate(list(alphabet)):
        dic[list(alphabet)[idx]] = idx+1
        
    queue = deque(msg)  
    while(queue):
        now_input = ''
        
        while(queue): # 현재 딕셔너리에 있는 가장 긴 입력 구하기
            cur_word = queue.popleft()

            if now_input + cur_word not in dic.keys():
                queue.appendleft(cur_word)
                break
            now_input += cur_word


        answer.append(dic[now_input])
        if queue:
            next_input = now_input + queue[0]
            if next_input not in dic.keys():
                dic[next_input] = index
                index += 1
        
    return answer

solution("KAKAO")
solution("TOBEORNOTTOBEORTOBEORNOT")
# 기댓값 〉	[20, 15, 2, 5, 15, 18, 14, 15, 20, 27, 29, 31, 36, 30, 32, 34]