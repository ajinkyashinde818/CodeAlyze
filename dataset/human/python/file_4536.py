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

cnt = collections.Counter(prime_factorize(N))
ans = 0
# print(cnt)
for val in cnt.values():
    # print(val)1
    m = 1
    while m*(m+1)//2 <= val:
        m += 1
    ans += m-1

print(ans)
