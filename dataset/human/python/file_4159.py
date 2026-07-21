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
c = collections.Counter(prime_factorize(int(input())))
num = 0

for k in c.values():
    temp_num = 1
    k_values = k
    while k_values > 0:
        if k_values - temp_num >= 0:
            k_values -= temp_num
            num += 1
            temp_num += 1
        else:
            k_values = 0
print(num)
