import collections
[n,m] = [int(i) for i in input().split()]
dic = collections.defaultdict(int)
for i in range(m):
  [a,b] = [int(j)-1 for j in input().split()]
  if a == 0:
    dic[b] += 1
  elif b == n-1:
    dic[a] += 1
if max(dic.values()) >= 2:
  print("POSSIBLE")
else:
  print("IMPOSSIBLE")
