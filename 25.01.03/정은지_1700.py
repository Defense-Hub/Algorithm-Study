n, k = map(int,input().split())
devices = list(map(int,input().split()))
array = []
answer = 0

for i in range(k):
    if devices[i] in array : 
        continue

    if len(array) < n :
        array.append(devices[i])
        continue

    priority = []
    for j in array: 
        if j in devices[i:]:
            priority.append(devices[i:].index(j))
        else:
            priority.append(101)
    target = priority.index(max(priority))
    array.remove(array[target])
    array.append(devices[i])
    answer += 1

print(answer)