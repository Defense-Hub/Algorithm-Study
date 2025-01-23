import sys
input = sys.stdin.readline

n = int(input())

def draw_star(n):
    if n == 1:
        return ["*"] # 여기서 문자열로 return 하면 틀림

    star = draw_star(n//3)
    array = []

    for i in star:
        array.append(i*3)
    for i in star:
        array.append(i + " "*(n//3) + i)
    for i in star:
        array.append(i*3)

    return array

def solution():
    array = draw_star(n)
    for i in array:
        print(i) # *i로 출력하면 공백이 생긴다 ..

solution()