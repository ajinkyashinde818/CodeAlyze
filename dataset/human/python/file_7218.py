from collections import deque
S = deque(input())
Q = int(input())
cnt = 0
for i in range(Q):
  x = list(input().split())
  if(int(x[0]) == 1):
    cnt += 1
  else:
    if((cnt+int(x[1])) % 2 == 1):
      S.appendleft(x[2])
    else:
      S.append(x[2])

S = list(S)
if(cnt % 2 == 1):
  S = S[::-1]
print("".join(S))
