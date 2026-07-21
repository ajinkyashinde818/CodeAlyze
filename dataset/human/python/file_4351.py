ma = lambda :map(int,input().split())
ni = lambda:int(input())
import collections
import math
import itertools
gcd = math.gcd
n  = ni()
def f(cnt):
    ret  = 0
    for i in range(1,10**9):
        ret +=i
        if ret>cnt:
            return i-1
def factorize(n):
    b = 2
    fct = [(1,1)]
    while b * b <= n:
        cnt =0
        while n % b == 0:
            n //= b
            cnt +=1
        if cnt >=1:
            fct.append((b,cnt))
        b = b + 1
    if n > 1:
        fct.append((n,1))
    return fct
d = factorize(n)
ans = 0
for num,cnt in d:
    ans += f(cnt)
print(ans-1)
