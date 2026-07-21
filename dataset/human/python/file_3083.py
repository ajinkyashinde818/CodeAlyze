from itertools import count

n = int(input())

prime_factor = {}
while n % 2 == 0:
    prime_factor[2] = prime_factor.get(2, 0) + 1
    n //= 2
f = 3
while f * f <= n:
    if n % f == 0:
        prime_factor[f] = prime_factor.get(f, 0) + 1
        n //= f
    else:
        f += 2
if n != 1:
    prime_factor[n] = prime_factor.get(n, 0) + 1

res = 0
for v in prime_factor.values():
    for i in count(1):
        if i > v:
            break
        res += 1
        v -= i

print(res)
