from collections import defaultdict
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

n = int(input())
if n == 1:
    print(0)
else:
    count = prime_factorize(n)
    count_dict = defaultdict(int)
    for c in count:
        count_dict[c] += 1
    ans = 0
    for key,value in count_dict.items():
        tmp = value
        m = 1
        while tmp >= m:
            tmp -= m
            m += 1
            ans += 1
    print(ans)
