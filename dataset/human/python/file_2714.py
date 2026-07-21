d, g = map(int, input().split())
lst = [list(map(int, input().split())) for i in range(d)]

def bitlist(n):
  res = []
  for i in range(2**n):
    pattern = []
    for j in range(n):
      if (i >> j) & 1:
        pattern.insert(0, True)
      else:
        pattern.insert(0, False)
    res.append(pattern)
  return res

res = 10000
pattern = bitlist(d)
for i in range(2**d):
  point = 0
  solve = 0
  for j in range(d):
    if pattern[i][j]:
      point += lst[j][0]*(j+1)*100 + lst[j][1]
      solve += lst[j][0]
  if point >= g:
    res = min(res, solve)
  else:
    yet = 0
    for k in range(d):
      if not pattern[i][k]:
        yet = k
    for l in range(lst[yet][0]-1):
      point += (yet+1)*100
      solve += 1
      if point >= g:
        res = min(res, solve)
        break
print(res)
