from collections import defaultdict

d = defaultdict(list)
goal, n = map(int, input().split())
for _ in range(n):
  f, t = map(int, input().split())
  d[f].append(t)
  d[t].append(f)
for current in d[1]:
  if goal in d[current]:
    print("POSSIBLE")
    break
else:
  print("IMPOSSIBLE")
