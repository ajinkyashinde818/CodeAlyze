from bisect import bisect_left

def sieve(n):
    srn = int(n ** 0.5)
    f = [False] * (srn + 1)
    res = []
    for i in range(2, srn+1):
        if f[i]:
            continue
        res.append(i)
        for j in range(2*i, srn+1, i):
            f[j] = True
    return res

def trial_division(n):
    res = dict()
    pn = sieve(n)
    for i in pn:
        while n % i == 0:
            res[i] = res.get(i, 0) + 1
            n //= i
    if n > 1:
        res[n] = 1
    return res

N = int(input())
pf = trial_division(N)
res = [i for i in range(10)]
for i in range(1, 10):
    res[i] = res[i-1] + i
ans = 0
for i in pf.values():
    idx = bisect_left(res, i)
    if i < res[idx]:
        idx -= 1
    ans += idx
print(ans)
