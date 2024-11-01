from itertools import product
from collections import defaultdict
from bisect import bisect_left

def solution(info, query):
    answer = []
    global information
    information = defaultdict(list)
    
    # info 배열에 있는 값들 information에 채우기
    for i in info:
        lst = i.split()
        keys = lst[:4]
        value = int(lst[-1])
        
        for j in product([keys[0], '-'],[keys[1], '-'],[keys[2], '-'],[keys[3], '-']):
            information[" ".join(j)].append(value)
    
    # dict안의 조합들을 점수순으로 정렬
    for i in information:
        information[i].sort()  

    # query 검사
    for i in query:
        query_language, query_job_type, query_ex_level, last = i.split(" and ")
        query_soulfood, score = last.split()  
        
        key = query_language+" "+ query_job_type+" "+ query_ex_level+" "+query_soulfood
        cnt = 0
        
        # bisect_left로 정렬되어있는 딕셔너리 value값에 현재 score가 들어갈 위치 찾기
        score_position = bisect_left(information[key],int(score))
        
        answer.append(len(information[key]) - score_position)
        
    return answer