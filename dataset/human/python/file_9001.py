from sys import stdin, setrecursionlimit
setrecursionlimit(100000)

s = stdin.readline().rstrip()
cand = ['eraser', 'erase', 'dreamer', 'dream']

for t in cand:
  s = s.replace(t, '')

  
if len(s) == 0:
  print("YES")
else:
  print("NO")
