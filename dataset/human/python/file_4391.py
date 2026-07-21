import bisect
from collections import defaultdict as dd
def factorize(n):
    b = 2
    fct = []
    while b * b <= n:
        while n % b == 0:
            n //= b
            fct.append(b)
        b = b + 1
    if n > 1:
        fct.append(n)
    return fct
N = int(input())
f = factorize(N)
dic=dd(int)
for val in f:
    if val!=1:
        dic[val] += 1
res = 0
ls = [1,3,6,10,15,21,28,36,45,55,66]
for val in dic.values():
    tmp = bisect.bisect_right(ls,val)
    res += tmp
print(res)
