n = int(input())
# 도화지 크기의 값이 0인 배열 만들기
array = [[0] * 100 for _ in range(100)]
answer = 0

for _ in range(n):
    height,width = map(int,input().split())
    # 배열을 돌며 1로 바꾸기
    for j in range(height,height+10):
        for h in range(width,width+10):
            array[j][h] = 1


# 배열을 돌며 1 개수세기
for i in array:
    for j in i:
        if j == 1:
            answer +=1           
print(answer)