import sys
from collections import deque

s = input()
q = int(input())
is_reverse = False
ds = deque(s)

for _ in range(q):
  tf = sys.stdin.readline().split()
  if len(tf) == 1:
    is_reverse = False if is_reverse else True
  else:
    if tf[1] == '1':
      if is_reverse:
        ds.append(tf[2])
      else:
        ds.appendleft(tf[2])
    else:
      if is_reverse:
        ds.appendleft(tf[2])
      else:
        ds.append(tf[2])
if is_reverse:
  ds.reverse()
ans = ''.join(list(ds))
print(ans)
