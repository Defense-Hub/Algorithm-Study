import sys
from collections import defaultdict
input = sys.stdin.readline

t = int(input())

def solution(): 
    w = input().strip()
    k = int(input().strip())

    dict = defaultdict(list)
    for i in range(len(w)):
        if w.count(w[i]) >= k: # k개 이상 등장하는 문자열인 경우
            dict[w[i]].append(i) # 좌표 저장
    
    if not dict:
        print(-1)
    else:
        three = int(1e9)
        four = 0
        
        tmp = k-1

        for key, val in dict.items():
            for i in range(len(val)):
                if i+tmp < len(val):
                    three = min(three, val[i+tmp] - val[i] + 1 )
                    four = max(four, val[i+tmp] - val[i] + 1)
        print(three, end=" ")
        print(four)
    

for _ in range(t):
    solution()