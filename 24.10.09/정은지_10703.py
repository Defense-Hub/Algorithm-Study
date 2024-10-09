import sys
import pprint

input = sys.stdin.readline
r,s = map(int,input().split())
meteor = [list(input().strip()) for _ in range(r)]

# 각 열에 대해, 유성과 땅의 최소 거리를 구한다.
dist = int(1e9)
for i in range(s):   
    column = [meteor[j][i] for j in range(r)]
    meteor_idx = 0
    ground_idx = int(1e9)

    # 유성이 존재하는 열만 최소거리 구해야함
    is_exist_meteor = False

    for j in range(len(column)):
        if column[j] == 'X':
            is_exist_meteor = True
            meteor_idx = max(meteor_idx,j)
        if column[j] == '#':
            ground_idx = min(ground_idx,j)

    if is_exist_meteor:
        dist = min(dist,ground_idx-meteor_idx-1)

# 유성들을 모두 dist만큼 아래로 내린다 (아래 행붙 검사한다)
for i in range(r-1,-1,-1):
    for j in range(s):
        if meteor[i][j] == 'X':
            meteor[i+dist][j] = 'X'
            meteor[i][j] = '.'

for i in meteor:
    for j in i:
        sys.stdout.write(j)
    sys.stdout.write('\n')