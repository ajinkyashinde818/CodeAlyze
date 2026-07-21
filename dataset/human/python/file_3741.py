def prime(n):
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

N = int(input())
a = prime(N)
a.sort()
import copy
b = copy.copy(a)
b = list(set(b))
b.sort()

ret = 0
for i in b:
    cnt = 0
    idx=0
    while True:
        idx += 1
        cnt = cnt + idx
        if a.count(i) >= cnt:
            ret += 1
        else:
            break

print(ret)
