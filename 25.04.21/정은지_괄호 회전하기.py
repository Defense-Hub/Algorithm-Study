# 18:46 ~ 19:00
from collections import deque

def solution(s):
    answer = 0
    n = len(s)
    open_string = ["[","(","{"]
    
    for i in range(n):
        new_string = s[i:]+s[:i]   
        
        stack = deque()
        is_valid = True
    
        for j in new_string:
            if j in open_string:
                stack.append(j)
            elif j == "]":
                if not stack or stack.pop() != "[":
                    is_valid = False
                    break         
            elif j == "}":
                if not stack or stack.pop() != "{":
                    is_valid = False
                    break  
            elif j == ")":
                if not stack or stack.pop() != "(":
                    is_valid = False
                    break  
            
        if is_valid and not stack:
            answer += 1

    return answer