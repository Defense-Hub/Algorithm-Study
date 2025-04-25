# 18:05 ~ 18:28

def binary_conversion(s):
    global removed_zero_cnt
    cnt= 0

    for i in s:
        if i=='1':
            cnt+=1

    removed_zero_cnt += (len(s)-cnt)

    new_s = convert_number_to_binary(cnt)
    return new_s

def convert_number_to_binary(s):
    new_s = ''

    while(s != 1):
        if s%2 == 1:
            new_s = '1' + new_s
        else:
            new_s = '0' + new_s
        s //= 2  
    new_s = '1' + new_s

    return new_s

def convert_binary_to_number(s):
    array = list(s)
    binary_number = 0
    n = len(array)
    
    for i in range(n):
        if array[i] == "1":
            binary_number += 2**(n-1-i)
    
    return binary_number
            
    
def solution(s):
    global removed_zero_cnt
    conversion_cnt = 0
    removed_zero_cnt = 0
    
    while(convert_binary_to_number(s) != 1):
        s = binary_conversion(s)
        conversion_cnt += 1
    
    return [conversion_cnt,removed_zero_cnt]

#solution("01110")
solution("110010101001")