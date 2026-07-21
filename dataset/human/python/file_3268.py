from collections import Counter


def prime_factorization(n):
    counter = Counter()
    max_pp = n
    while n % 2 == 0:
        counter[2] += 1
        n //= 2
    p = 3
    while p ** 2 <= max_pp:
        if n % p == 0:
            counter[p] += 1
            n //= p
        else:
            p += 2
    if n != 1:
        counter[n] += 1
    return counter


N = int(input())
prime_counter = prime_factorization(N)
ans = 0
for key in prime_counter.keys():
    for e in range(1, N):
        if prime_counter[key] >= e:
            prime_counter[key] -= e
            ans += 1
            e += 1
        else:
            break

print(ans)
