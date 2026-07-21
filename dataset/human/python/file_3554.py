from collections import Counter

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

ans = 0
n = 1
for i, v in Counter(prime_factorize(N)).items():
    # print(i, v)
    while True:
        # print("v", v)
        v -= n
        if v >= 0:
            ans += 1
            n += 1
        else:
            break
    n = 1
print(ans)
