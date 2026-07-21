def ZZ(): return list(map(int, input().split()))
def Z(): return int(input())

N, K = ZZ()
A = ZZ()
for i in range(N):
    A[i] -= 1

def mul(a, b):
    return [a[b[i]] for i in range(len(a))]

def beki(a, b):
    res = list(range(len(a)))
    while b > 0:
        if b & 1:
            res = mul(res, a)
        a = mul(a, a)
        b >>= 1
    return res

A = beki(A, K)
print(A[0] + 1)
