from collections import Counter
N = int(input())

def trial_division(n):
    prime_factors = list()
    while n % 2 == 0:
        prime_factors.append(2)
        n //= 2
    p = 3
    while p * p <= n:
        if n % p == 0:
            prime_factors.append(p)
            n //= p
        else:
            p += 2
    if n != 1:
        prime_factors.append(n)
    return prime_factors

C = Counter(trial_division(N))
ans = 0
for key,value in C.items():
    check = 0
    for i in range(1,value+1):
        check = (i * (i + 1))//2
        if value >= check:
            ans += 1
        else:
            break
print(ans)
