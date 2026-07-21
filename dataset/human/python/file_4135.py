import collections


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
n = int(input())
c = collections.Counter(prime_factorize(n))
cnt = list(c.values())
# print(cnt)
for i in range(len(cnt)):
    mainasu = 1
    while True:
        if cnt[i] == 0 or cnt[i] < mainasu:
            break
        # print(cnt[i], mainasu)
        cnt[i] -= mainasu
        mainasu += 1
        ans += 1


print(ans)
