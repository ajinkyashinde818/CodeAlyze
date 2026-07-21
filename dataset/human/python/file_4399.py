import collections

def prime_factorize(n):
    prime_factor_list = []
    while n%2 == 0:
        prime_factor_list.append(2)
        n //= 2
    f = 3
    while f*f <= n:
        if n%f == 0:
            prime_factor_list.append(f)
            n //= f
        else:
            f += 2
    if n != 1:
        prime_factor_list.append(n)
    
    prime_factor = collections.Counter(prime_factor_list)

    return prime_factor

n = int(input())
c = prime_factorize(n)
ans = 0
for i in c.values():
    tmp = 0
    for j in range(1, i+1):
        tmp += j
        if tmp > i:
            break
        ans += 1
print(ans)
