import sys

N, K = map(int, input().split())
A = list(map(int, input().split()))

i = 1
l = [1] * N
s = set([1])
n = 1
while True:
    n = A[n-1]
    if n in s:
        l = l[:i]
        mod = i - l.index(n)
        init_len = l.index(n)
        break
    else:
        l[i] = n
        s.add(n)
        i += 1

if K < init_len:
    print(l[K])
else:
    rest = ((K-init_len) % mod)
    print(l[init_len+rest])
