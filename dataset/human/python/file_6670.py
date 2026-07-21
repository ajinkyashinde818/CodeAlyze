import sys
from collections import deque as dq
input = sys.stdin.readline
S = dq(list(input())[: -1])
Q = int(input())
rev = 0
ap = [dq([]), dq([])]
for _ in range(Q):
  t = input().split()
  if int(t[0]) == 1: rev = (rev + 1) % 2
  else:
    f, c = int(t[1]) - 1, t[2]
    if (f + rev) % 2: S.append(c)
    else: S.appendleft(c)
if rev: S.reverse()
print("".join(S))
