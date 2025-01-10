import sys
input = sys.stdin.readline

n = int(input())

def solution():
    end = 0
    answer = 0
    array = []

    for i in range(0, n):
        a, b = map(int,input().split())
        array.append([a,b])

    array.sort(key = lambda x: (x[1], x[0]))

    for nstart, nend in array:
        if end <= nstart:
            answer += 1
            end = nend
    print(answer)

solution()
