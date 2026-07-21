import collections

def p(n):
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
s = p(n)
c = collections.Counter(s)
t = list(c.values())
m = 0

for x in t:
    
    a = 1

    for j in range (100):
        if (x - a >= 0):
            x = x - a
            m = m + 1
            a = a + 1
        else:
            break

print(m)
