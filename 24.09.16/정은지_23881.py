n,k = map(int,input().split())
numbers = list(map(int,input().split()))
cnt = 0

def selection(numbers):
    global cnt
    ans = []
    for i in range(n-1, 0, -1):
        max,index = numbers[0],0

        for j in range(0, i+1):
            if numbers[j] > max:
                max, index = numbers[j], j
        if i != index:
            numbers[i], numbers[index] = numbers[index], numbers[i]
            cnt += 1

            if cnt == k:
                ans.append(numbers[index])
                ans.append(numbers[i])
                return ans

    ans.append(-1)
    return ans

print(*selection(numbers))

