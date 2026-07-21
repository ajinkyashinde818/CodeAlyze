import math,string,itertools,fractions,heapq,collections,re,array,bisect,sys,random,time

sys.setrecursionlimit(10**7)
inf=10**20
mod=10**9+7

def LI(): return list(map(int,input().split()))
def I(): return int(input())
def LS(): return input().split()
def S(): return input()

def main():
  n,m=LI()

  l=[]
  for _ in range(m):
    a,b=LI()

    if a==1:
      l.append(b)
    elif b==n:
      l.append(a)

  x=len(l)
  y=len(list(set(l)))

  if x!=y:
    return 'POSSIBLE'
  return 'IMPOSSIBLE'

print(main())
