import sys
import collections

N = int(input())

def factorize(n):
    a = []
    while n % 2 == 0:
        a.append(2)
        n //= 2
    f = 3
    while f * f <= n:
        if n % f == 0:
            a.append(f)
            n //= f
        else:
            f += 2
    if n != 1:
        a.append(n)
    return collections.Counter(a).items()

list = factorize(N)
ans = 0
tmp = [0,1,3,6,10,15,21,28,36,45,55,66,78,91]
for k,v in list:
    for j in range(len(tmp)):
        if v < tmp[j]:
            ans += j - 1
            break

print(ans)
