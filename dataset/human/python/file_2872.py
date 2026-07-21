import collections
n = int(input())
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
c = collections.Counter(a)
l = list(c.values())

def func(n):
    i = 2
    counter = 1
    while counter <= n:
        counter += i
        i += 1
    return i-2

print(sum(map(func, l)))
