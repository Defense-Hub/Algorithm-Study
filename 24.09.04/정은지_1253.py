n = int(input())
numbers = list(map(int,input().split()))
numbers.sort()
answer = 0

for i in range(n):
    # 투포인터 알고리즘
    start = 0
    end = n-1

    while start<end:
        if numbers[start] + numbers[end] == numbers[i]:
            # numbers[start]와 numbers[end]가 자기자신이 아닌지 체크 
            if start == i:
                start += 1
            elif end == i:
                end -= 1
            else:
                answer += 1
                break
        elif numbers[start] + numbers[end] < numbers[i]:
            start += 1
        elif numbers[start] + numbers[end] > numbers[i]:
            end -= 1

print(answer)
