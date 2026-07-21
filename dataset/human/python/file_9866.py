import sys
read = sys.stdin.buffer.read
readline = sys.stdin.buffer.readline
readlines = sys.stdin.buffer.readlines
import sys
sys.setrecursionlimit(4100000)

n,m= map(int,readline().split())
a = list(map(int,readline().split()))

if a[0] == 1:
  print(1)
  exit()
  
d = set([0])
def dfs(now,cc,d):
    if cc == m:
      return now
    else:
      next = a[now]
      next -= 1
      if not next in d:
        d.add(next)
        return dfs(next,cc+1,d)
      else:
        d = list(d)
        for i,di in enumerate(d[::-1]):
          if di == next:
            return (i+1,cc,now)

def f(now,cc):
    global mar
    if cc == mar:
      return now
    else:
      next = a[now]
      next -= 1
      return f(next,cc+1)
    
res = dfs(0,0,d)
if type(res) == int:
  print(res+1)
else:
  m -= res[1]
  mar = m % res[0]
  print(f(res[2],0)+1)
