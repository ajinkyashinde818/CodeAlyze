import collections

n, m = map(int,input().split())
a = []

for i in range(m):
  x, y = map(int,input().split())
  if x == 1: #1の島から行ける島
    a.append(y)
  if y == n: #5の島へ行ける島
    a.append(x)

c = collections.Counter(a)

if c.most_common()[0][1] == 2:
  print("POSSIBLE")
else:
  print("IMPOSSIBLE")
