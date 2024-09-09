n = int(input())
answer = 0
graph = []

# 플로이드 워셜 알고리즘 사용 (n은 최대 50)
# 서로 친구인 경우 = 친구i에서 친구j까지 거리가 1
# 한 다리 건너서 아는 친구인 경우 = 친구i에서 친구j까지 거리가 2

for _ in range(n):
    graph.append(list(input().strip()))

twoFriends = [[False] * n for _ in range(n)]

for k in range(n):
  for i in range(n):
    for j in range(n):
      if i == j:
        continue
      # 2-친구인 경우 (서로 친구거나 건너서 친구인 경우)
      if graph[i][j] == 'Y' or (graph[i][k] == 'Y' and graph[k][j] =='Y'):
        twoFriends[i][j] = True


for twoFriend in twoFriends:
    cnt = 0
    for i in twoFriend:       
        if i:
            cnt += 1
    answer = max(answer,cnt)

print(answer)