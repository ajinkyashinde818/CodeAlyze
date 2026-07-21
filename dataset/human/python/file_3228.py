import sys
import math


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

prims = prime_factorize(n)

prim_set = set(prims)

deleted_prims = {}

ans = 0
for prim in prim_set:
    while True:
        if prim not in deleted_prims:
            deleted_prims[prim] = 1
        times = deleted_prims[prim]
        # print(times)
        if times == 0:
            break
        if times <= prims.count(prim):
            # 操作できる
            ans += 1
            for i in range(times):
                prims.remove(prim)
            deleted_prims[prim] += 1
            # print("OK", prims)

        else:
            break

print(ans)
