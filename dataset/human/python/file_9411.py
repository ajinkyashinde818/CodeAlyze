N, K = [int(n) for n in input().split()]
A = [int(n) for n in input().split()]

f = {}

def town(k):
    t = 1
    i = 0
    while i < k:
        f[t] = i
        t = A[t-1]
        i += 1

        if t in f:
            j = f[t]
            r = i - j
            k = i + (k - i) % r
    return t

print(town(K))
