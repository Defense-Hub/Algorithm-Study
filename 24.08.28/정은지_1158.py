from collections import deque
n,k = map(int,input().split())
lst = deque(i for i in range(1,n+1))
answer = deque()

while lst:
    for _ in range(k-1):
        lst.append(lst.popleft())
    answer.append(lst.popleft())

print("<",end="")
for i in range(len(ans)-1):
    print(ans[i],end = ", ")
print(ans[-1],end="")
print(">")