from collections import defaultdict

def pr(n):
    d = defaultdict(lambda:0)
    i = 2
    while (n > 1) and (i < int(n**0.5)+1):
        if n % i == 0:
            d[i] += 1
            n //= i
        else:
            i += 1
            
    if n > 1:
        d[n] += 1
    return d

def t(x):
    i = 1
    while x >= i:
        x -= i
        i += 1
    return i-1

n = int(input())
d = pr(n)
r = 0
for i in d.values():
    r += t(i)
print(r)
