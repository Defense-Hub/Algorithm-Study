import sys
input = sys.stdin.readline

n = int(input())
s = [input().strip() for _ in range(n)]
words = {} 

def solution():
    for i in s: 
        x = len(i)-1 
        for j in i :
            if j in words:
                words[j] += 10**x 
            else :
                words[j] = 10**x
            x -= 1

    sorted_words = sorted(words.values(), reverse=True)
    result = 0
    num = 9
    for k in sorted_words:
        result += k * num 
        num -= 1

    print(result)

solution()