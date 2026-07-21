from collections import defaultdict
L = int(input())
ans = 0
def prime_factorize(n):
    a = defaultdict(int)
    while n % 2 == 0:
        a[2] += 1
        n //= 2
    f = 3
    while f * f <= n:
        if n % f == 0:
            a[f]+=1
            n //= f
        else:
            f += 2
    if n != 1:
        a[n]+=1
    return a

L_f = prime_factorize(L)
for p in L_f.values():
    k = 1
    while p  >= k :
        p -= k
        k += 1
        ans += 1
print(ans)
