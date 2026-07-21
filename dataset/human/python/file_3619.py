from math import sqrt
def factorint(n):
    d = {}
    for i in range(2, int(sqrt(n))+1):
        c = 0
        q, r = divmod(n, i)
        while not r:
            c += 1
            n = q
            q, r = divmod(n, i)
        if c:
            d[i] = c
    if n != 1:
        d[n] = 1
    return d

n = int(input())
if n == 1:
    print(0)
else:
    d = factorint(n)
    s = 0
    for v in d.values():
        s += int((sqrt(8*v+1)-1)/2)
    print(s)
