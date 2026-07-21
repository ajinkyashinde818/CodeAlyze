import collections
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
    return a
def numcount(n):
    i = 1
    while True:
        n -= i
 
        if n <= i:
            break
        i += 1
    return i
A = int(input())
L = factorize(A)
C = collections.Counter(L)
ret = 0
for c in C:
    ret += numcount(C[c])
print(ret)
