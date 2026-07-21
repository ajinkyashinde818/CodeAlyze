import sys
def I(): return int(sys.stdin.readline().rstrip())
def LI(): return list(map(int,sys.stdin.readline().rstrip().split()))  #空白あり
def LI2(): return list(map(int,sys.stdin.readline().rstrip()))  #空白なし
def S(): return sys.stdin.readline().rstrip()
def LS(): return list(sys.stdin.readline().rstrip().split())  #空白あり
def LS2(): return list(sys.stdin.readline().rstrip())  #空白なし

N = I()

import math

d = {}
for i in range(2,math.floor(math.sqrt(N))+1):
    if N % i == 0:
        r = 0
        while N % i == 0:
            N //= i
            r += 1
        d[i] = r
if N != 1:
    d[N] = 1

ans = 0
for i in d.keys():
    r = d[i]
    b = 1
    a = 0
    while r > 0:
        r -= b
        if r >= 0:
            b += 1
            a += 1
        else:
            break
    ans += a

print(ans)
