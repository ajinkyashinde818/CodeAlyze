import math,itertools,fractions,heapq,collections,bisect,sys,queue,copy

sys.setrecursionlimit(10**7)
inf=10**20
mod=10**9+7
dd=[(-1,0),(0,1),(1,0),(0,-1)]
ddn=[(-1,0),(-1,1),(0,1),(1,1),(1,0),(1,-1),(0,-1),(-1,-1)]

def LI(): return [int(x) for x in sys.stdin.readline().split()]
def LF(): return [float(x) for x in sys.stdin.readline().split()]
def I(): return int(sys.stdin.readline())
def F(): return float(sys.stdin.readline())
def LS(): return sys.stdin.readline().split()
def S(): return input()

def main():
  n,k=LI()
  l=LI()

  ans=[[] for _ in range(n)]
  basho=0
  f=inf
  for i in range(2*n+1):
    if f==inf and len(ans[basho])>1:
      f=basho
    ans[basho].append(i)
    basho=l[basho]-1

  # print(ans)
  # print(f)

  if k<(2*n+1):
    for i,x in enumerate(ans):
      if k in x:
        return i+1

  k-=ans[f][0]
  span=ans[f][2]-ans[f][1]
  # print(span)
  xx=k%span
  # print(k,span,xx)
  start=f
  while xx>0:
    start=l[start]-1
    xx-=1

  return start+1

# main()
print(main())
