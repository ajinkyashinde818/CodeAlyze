import sys
INF = 1 << 60
MOD = 10**9 + 7 # 998244353
sys.setrecursionlimit(2147483647)
input = lambda:sys.stdin.readline().rstrip()

def prime_factorization(n):
    assert n > 1
    factor=[]
    for d in range(2, int(n ** .5) + 1):
        while n % d == 0:
            n //= d
            factor.append(d)
    if n != 1: factor.append(n)
    return factor

from collections import Counter
def resolve():
    n = int(input())
    if n == 1:
        print(0)
        return
    C = Counter(prime_factorization(n))
    res = 0
    for v in C.values():
        n = 1
        while 2 * v >= n * (n + 1):
            n += 1
        res += n - 1

    print(res)
resolve()
