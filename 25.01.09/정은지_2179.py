import sys
input = sys.stdin.readline

n = int(input())
array = [input().strip() for _ in range(n)]

def get_common_length(str1, str2):
    length = min(len(str1),len(str2))
    cnt = 0
    for i in range(length):
        if (str1[i] == str2[i]):
            cnt+=1
        else:
            break
    return cnt

def solution(): 
    answer = []
    cnt = 0

    for i in range(n):
        for j in range(i+1,n): # i번째 문자열과 그 뒤의 문자열만 비교        
            common_length = get_common_length(array[i], array[j])
            if common_length > cnt: # 더 클때만 비교
                cnt = common_length
                answer.clear()
                answer.append(array[i])
                answer.append(array[j])
    for i in answer:
        print(i)

solution()
