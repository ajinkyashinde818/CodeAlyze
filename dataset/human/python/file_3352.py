import collections
num = [1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,34,35,36,37]
N = int(input())
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
ans = 0    
a = prime_factorize(N)
cor = collections.Counter(a)
for v in cor.values():
    tmp = 0
    for nn in num:
        v -= nn
        if v >= 0:
            ans += 1
        else:
            break
print(ans)
