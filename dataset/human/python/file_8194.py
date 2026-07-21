import math,string,itertools,fractions,heapq,collections,re,array,bisect,sys,random,time

sys.setrecursionlimit(10**7)
inf = 10**20
mod = 10**9 + 7

def LI(): return list(map(int, input().split()))
def II(): return int(input())
def LS(): return input().split()
def S(): return input()


def main():
    k,s = LI()
    r = 0
    for x in range(k+1):
        for y in range(k+1):
            z = s-x-y
            if z > k:
                continue
            if z < 0:
                break
            r += 1

    return r


print(main())
