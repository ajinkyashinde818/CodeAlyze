import sys
sys.setrecursionlimit(10 ** 9)

n,k = map(int,input().split())
a = list(map(int,input().split()))

r = []
u = [False for _ in range(n)]
def dfs(x):
  if u[x]:
    return x
  else:
    u[x] = True
    r.append(x)
    return dfs(a[x]-1)

b = dfs(0)
for i in range(len(r)):
  if b == r[i]:
    break
#print(b,i,r)
if k >= i:
  print(r[i+(k-i)%(len(r)-i)]+1)
else:
  print(r[k]+1)
