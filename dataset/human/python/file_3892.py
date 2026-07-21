from collections import Counter
def primeFactorize(n):
    fac = []
    if n < 2: return fac
    while n%2 == 0:
        n //= 2
        fac.append(2)
    for i in range(3,int(n**0.5)+1,2):
        while n%i == 0:
            n //= i
            fac.append(i)
    if n != 1: fac.append(n)
    return fac

n = int(input())
ans = 0
cnt = Counter(primeFactorize(n))
for v in cnt.values():
    c = 1
    while c <= v:
        ans += 1
        v -= c
        c += 1
print(ans)
# print(primeFactorize(n))
# print(cnt)
