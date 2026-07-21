from collections import deque
S = input()
S = [S[i] for i in range(len(S))]
S = deque(S)                         
Q = int(input())
rev = 1
for i in range(Q):
  comm = input()
  if comm == "1":
    rev *= -1
  else:
    T, F, C = comm.split()
    F = int(F) * 2 - 3
    if rev * F == 1:
      S.append(C)
    else:
      S.appendleft(C)
S = list(S)
ans = ""
for i in range(len(S)):
  ans += S[i * rev + (rev-1) // 2]
print(ans)
