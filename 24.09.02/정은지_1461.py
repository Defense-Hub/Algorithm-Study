n,m = map(int,input().split())
positions = list(map(int,input().split()))

# 0으로 선언해야 n이 1일 때 인덱스 오류 안남
lLst = [0]
rLst = [0]

for pos in positions:
    if pos < 0:
        lLst.append(abs(pos))
    else:
        rLst.append(pos)

lLst.sort()
rLst.sort()

# 가장 큰 값 (0으로 돌아오지 않을 값)
maxVal = max(lLst[-1], rLst[-1])
answer = 0

while lLst:
    answer += lLst[-1] * 2
    cnt = 0
    while lLst and cnt < m :
        cnt += 1
        lLst.pop()

while rLst:
    answer += rLst[-1] * 2
    cnt = 0
    while rLst and cnt < m :
        cnt += 1
        rLst.pop()

print(answer - maxVal)
