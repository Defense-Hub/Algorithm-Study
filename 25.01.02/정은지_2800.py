import sys
from itertools import combinations
input = sys.stdin.readline

expression = list(input().strip())

def solution():
    n = len(expression)
    answer = set()
    left_exp = []
    right_exp = [] 
    
    for i in range(n):
        if expression[i] == "(":
            left_exp.append(i)
        elif expression[i] == ")":
            right_exp.append((left_exp.pop(), i))
    
    for i in range(1,n+1):
        comb = list(combinations(right_exp,i))

        for j in comb:
            new_expression = expression[:] # 문자열 복사
            for x,y in j:
                new_expression[x] = ''
                new_expression[y] = ''
            answer.add("".join(new_expression))

    answer = list(answer)
    answer.sort()
    for i in answer:
        print(i)

solution()