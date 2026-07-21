n = int(input())

""" def make_divisors(n):
    divisors = []
    for i in range(1, int(n**0.5)+1):
        if n % i == 0:
            divisors.append(i)
            if i != n // i:
                divisors.append(n//i)

    divisors.sort()
    return divisors

print(make_divisors(n))
#[1, 2, 3, 4, 6, 8, 12, 24] """

def prime_decomposition(n):
    i = 2
    table = []
    while i * i <= n:
        while n % i == 0:
            n /= i
            table.append(i)
        i += 1
    if n > 1:
        table.append(n)
    return table
li = prime_decomposition(n)
#print(prime_decomposition(n))
#[2, 2, 2, 3.0]
import collections
c = collections.Counter(li)
v_li = list(c.values())
#print(v_li)
#[3, 1]
ans = 0
for v in v_li:
    ans += 1
    tmp = 1
    while v >= tmp:
        v -= tmp
        tmp += 1
        if v >= tmp:
            ans += 1
print(ans)
