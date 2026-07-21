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


import collections
n = int(input())
if n == 1:
    print(0)
    exit()
c = collections.Counter(prime_factorize(n))
t = sorted(c.values())
max_c = max(t)
calc_list = []
ans = 0
a = 0
i = 1
while a <= max_c:
    a = i * (i + 1) // 2
    while t[0] < a:
        ans += i - 1
        t.pop(0)
        if len(t) == 0:
            break
    i += 1
print(ans)
