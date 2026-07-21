import math,string,itertools,fractions,heapq,collections,re,array,bisect,sys,random,time

sys.setrecursionlimit(10**7)
inf=10**20
mod=10**9+7

def LI(): return list(map(int,input().split()))
def I(): return int(input())
def LS(): return input().split()
def S(): return input()

def main():
  n=I()
  l=LI()

  al=sum(l)

  sm=0
  sa=inf
  for x in l[:-1]:
    sm+=x
    sa=min(sa,abs(sm-(al-sm)))

  return sa

print(main())
