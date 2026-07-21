from collections import deque
d = deque()
S = input()
d.append(S)
N = int(input())
direct = 1
for i in range(N):
  X = input().split()
  if len(X) == 1:
    direct *= -1
  else:
    if (X[1] == "1" and direct == 1) or (X[1] == "2" and direct == -1):
      d.appendleft(X[2])
    else:
      d.append(X[2])
      
S = "".join(list(d))
print(S) if direct == 1 else print(S[::-1])
