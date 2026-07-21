from collections import defaultdict
n, m = map(int, input().split())
d = defaultdict(list)
for i in range(m):
  a, b = map(int, input().split())
  d[a].append(b)
ans = ''
for mid in d[1]:
  if ans == '':
    for goal in d[mid]:
      if goal == n:
        ans = 'POSSIBLE'
        break
if ans == '':
  ans = 'IMPOSSIBLE'
print(ans)
