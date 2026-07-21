import bisect, copy, heapq, math, sys
from collections import *
from functools import lru_cache
from itertools import accumulate, combinations, permutations, product
def input():
    return sys.stdin.readline()[:-1]
def ruiseki(lst):
    return [0]+list(accumulate(lst))
def celi(a,b):
    return -(-a//b)
sys.setrecursionlimit(5000000)
mod=pow(10,9)+7
al=[chr(ord('a') + i) for i in range(26)]
direction=[[1,0],[0,1],[-1,0],[0,-1]]

n=int(input())
x=list(map(int,input().split()))

N = 10**6
g1 = [1, 1] # 元テーブル
g2 = [1, 1] #逆元テーブル
inverse = [0, 1] #逆元テーブル計算用テーブル

for i in range( 2, N + 1 ):
    g1.append( ( g1[-1] * i ) % mod )
    inverse.append( ( -inverse[mod % i] * (mod//i) ) % mod )
    g2.append( (g2[-1] * inverse[-1]) % mod )

kaijo=1
for i in range(n-1):
    kaijo*=n-i-1
    kaijo%=mod
# print(kaijo)

ans=0
cnt=0
for i in range(n-1):
    y1,y2=x[i],x[i+1]
    sa=y2-y1
    cnt+=g1[n-1]*g2[i+1]*g1[i]
    ans+=cnt*sa
    # print(g1[n-1]*g2[i+1]*g1[i])
    ans%=mod
    # print(ans)
# print(g1[:10])
# print(g2[:10])
print(ans)
