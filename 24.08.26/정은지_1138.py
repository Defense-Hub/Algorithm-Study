n = int(input())
lst = list(map(int, input().split()))
array = [0]*n

for i in range(n):
    cnt = 0
    # array 체크
    for j in range(n):
        if cnt==lst[i] and array[j] == 0:
            array[j] = i+1
            break
        elif(array[j] == 0):
            cnt+=1
print(*array)
