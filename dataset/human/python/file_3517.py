import collections
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

c = collections.Counter(prime_factorize(N))
c_values = list(c.values())

list = []
number = 1

cnt = 2
while len(list) < 100:
    for j in range(cnt):
        list.append(number)
    number += 1
    cnt += 1

ans = 0
for i in range(len(c_values)):
    ans += list[c_values[i]-1]

print(ans)
