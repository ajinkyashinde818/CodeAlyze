from collections import defaultdict
N = int(input())

def primeFactorization(n):
    res = defaultdict(int)
    m = int(n**0.5)
    for i in range(2,m+1):
        while n % i == 0:
            n = n//i
            res[i] += 1
    if n > 1:
        res[n] = 1
    return res

dic = primeFactorization(N)

ans = 0
for k,v in dic.items():
    n = 1
    while v >= n*(n+1)//2:
        ans += 1
        n += 1

print(ans)
