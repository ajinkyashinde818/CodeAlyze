from collections import deque

n, k = list(map(int, input().split(' ')))
a = list(map(int, input().split(' ')))

loop = []
visited = set()
s = set([1])
loop_creating = False
last = 1

while True:
  if loop_creating and len(visited) == 0:
    break
  
  if k == len(s) - 1:
    print(last)
    exit(0)

  nex = a[last - 1]

  if nex in visited:
    visited.remove(nex)
    loop.append(nex)
    loop_creating = True
  elif nex in s:
    visited.add(nex)
  else:
    s.add(nex)

  last = nex

rem = k - len(s)
print(loop[rem % len(loop)])
