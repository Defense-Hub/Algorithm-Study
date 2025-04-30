# 16:24 ~ 17:00

# x과 y를 각각 이진수로 변환한 후 xor
def bitwise_xor(x,y):
    max_length = max(x.bit_length(),y.bit_length())
    
    binary_x = list(bin(x)[2:].zfill(max_length))
    binary_y = list(bin(y)[2:].zfill(max_length))
    result = ""

    for i in range(max_length):
        if binary_x[i] == binary_y[i]:
            result += "0"
        else:
            result += "1"

    if result == '':
        return 0
    
    return int(result,2)

def solution(data, col, row_begin, row_end):
    answer = 0
    
    # 테이블의 튜플을 col번째 컬럼의 값을 기준으로 오름차순 정렬을 하되, 만약 그 값이 동일하면 기본키인 첫 번째 컬럼의 값을 기준으로 내림차순 정렬
    data.sort(key=lambda x:(x[col-1],-x[0]))
    
    for i in range(row_begin-1, row_end):
        s_val = 0
        for j in data[i]:
            s_val += j%(i+1)
        answer = bitwise_xor(answer,s_val) 

    return answer

solution([[2, 2, 6], [1, 5, 10], [4, 2, 9], [3, 8, 3]], 2, 2, 3)