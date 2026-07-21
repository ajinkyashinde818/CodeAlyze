from collections import Counter
import bisect

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
L = Counter(prime_factorize(n))
A = [0]*50
for i in range(50):
    cnt = 1
    while i >= (cnt+1)*(cnt+2)//2:
        cnt += 1
    A[i] = cnt
ans = 0
for c in L.values():
    ans += A[c]
print(ans)
