# 15:01 ~ 15:48

from itertools import combinations

# valid한 비밀 코드인지 검사
def check_valid_code(q,ans,code):
    for i in range(len(q)):
        cnt, q_list = ans[i], q[i]
        intersection_cnt = len(set(q_list)&set(code))
        
        if cnt != intersection_cnt:
            return False      

    return True

def solution(n, q, ans):
    answer = 0
    m = len(q)
    numbers= [i for i in range(1,n+1)]
    generated_codes = list(combinations(numbers,5))
    
    for code in generated_codes:
        if check_valid_code(q,ans,code):
            answer += 1

    return answer