target = int(input())
ans = abs(100 - target) 
m = int(input())

if m != 0: 
    broken_btns = set(input().split())
else:
    broken_btns = set()

# 한번 더 풀어보자.. . 
for num in range(1000001): 
    for n in str(num):
        if n in broken_btns: # 해당 숫자가 번호를 눌러서 만들 수 없는 경우엔 스탑
            break
    else: # 번호를 눌러서 만들 수 있는 경우엔
    	# min(기존답, 번호를 누른 횟수 + 해당 번호로부터 타겟까지의 차이)
        ans = min(ans, len(str(num)) + abs(num - target))

print(ans)