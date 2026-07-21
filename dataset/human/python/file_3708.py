from collections import Counter

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
    return Counter(a)

def check(j):
    if j <= 2:
        return 1
    else:
        tmp = int((j * 2) ** 0.5)
        while 1:
            if tmp * (tmp + 1) <= j * 2:
                return tmp
            else:
                tmp -= 1
        # return int((j * 2) ** 0.5)


N = int(input())
ans = 0
for i, j in prime_factorize(N).items():
    ans += check(j)
print(ans)
