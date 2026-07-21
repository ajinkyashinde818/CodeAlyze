import math
import collections

def prime_factorize(n):
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
    return a

n = int(input())

c = collections.Counter(prime_factorize(n))

d = list(c.values())

# d = 2 #素数
ans = 0
# print(c)
x = 1
for i in d:
    s = i
    x=1
    while s>0:
        s = s - x
        # print(x,"引いて",s)
        x +=1
        if s>=0:
            ans+=1

print(ans)
