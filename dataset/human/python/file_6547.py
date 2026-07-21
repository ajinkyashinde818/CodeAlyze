from collections import deque
S = input()
S = deque(S)
N = int(input())

rev = 0

for i in range(N):
  Q = input().split()
  if Q[0] == "1":
    rev += 1
    rev %= 2
  else:
    if (rev + int(Q[1])) % 2 == 1:
      S.appendleft(Q[2])
    else:
      S.append(Q[2])
S = "".join(S)
if rev == 1:
  S = S[::-1]
print(S)
