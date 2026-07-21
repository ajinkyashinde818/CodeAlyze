import sys
stdin = sys.stdin
sys.setrecursionlimit(10**9)
ni = lambda: int(ns())
na = lambda: list(map(int, stdin.readline().split()))
nn = lambda: list(stdin.readline().split())
ns = lambda: stdin.readline().rstrip()

s = ns()
q = ni()
h = 0

from collections import deque
ss=deque(list(s))

for i in range(q):
  que = nn()
  if int(que[0]) == 1:
    h += 1
  else:
    b = int(que[1])
    c = que[2]
    if (h+b)%2 == 0:
      ss.append(c)
    else:
      ss.appendleft(c)

ss = list(ss)

if h%2 == 1:
  ss = reversed(ss)

print(''.join(ss))
