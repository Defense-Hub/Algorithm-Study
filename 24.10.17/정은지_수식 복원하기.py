# 10진수를 base진수로 변환
def convertTobase(number, base):
    # A, B는 음이 아닌 두 자릿수 이하의 정수
    if len(number) == 1:
        return int(number)
    else:
        return base * int(number[0]) + int(number[1])

# base진수를 10진수로 변환
def convertToNum(number, base):
    if number == 0:
        return 0
    string = ''
    while number>0:
        string = str(number % base)+ string
        number //= base
    return int(string)
    
# 교집합 구하는 함수
def intersection(arrays,maxNum):
    if arrays:
        # 첫 번째 배열을 기준
        intersection = set(arrays[0])

        # 나머지 배열들과 교집합을 계속 구함
        for array in arrays[1:]:
            # 교집합 구하는법
            intersection &= set(array)

        return list(intersection)
    return [i for i in range(maxNum+1,10)]

# 어떤 식의 base진법 계산 결과 얻는 함수
def get_base_result(x,y,sign,base):         
    left = convertTobase(x,base)
    right = convertTobase(y,base)

    if sign == '+':
        return left + right
    else:
        return left - right

def solution(expressions):
    answer = [] 
    certain_expressions = []
    uncertain_expressions = []
    bases = []
    maxNum = 0
    
    for expression in expressions:
        x,sign,y,equal_sign,result = expression.split()
        
        # 최소 진법 찾기 
        for i in x:
            maxNum = max(maxNum,int(i))
        for i in y:
            maxNum = max(maxNum,int(i))
            
        if result == 'X':
            uncertain_expressions.append([x,sign,y])
        else:
            certain_expressions.append([x,sign,y,result])

    for certain in certain_expressions:
        x,sign,y,result = certain
        # 수식이 정상적으로 동작하는 base들 저장
        can_be_base = []
        
        for i in range(maxNum + 1,10):
            tmp = get_base_result(x,y,sign,i)     

            if convertToNum(tmp,i) == int(result):              
                can_be_base.append(i)
        bases.append(can_be_base)

    bases = intersection(bases,maxNum)

    for uncertain in uncertain_expressions:
        x,sign,y = uncertain
        
        # 안겹치도록 음수 설정
        result = -1

        for base in bases:
            tmp = get_base_result(x,y,sign,base) 

            n = int(convertToNum(tmp,base))

            if result < 0:
                result = n
            elif result != n:             
                result = "?"
                break

        
        answer.append(f"{str(x)} {sign} {str(y)} = {result}")
    return answer