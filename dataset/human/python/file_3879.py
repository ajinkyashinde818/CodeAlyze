n = int(input())


def factorization(n):
    retval = []
    tmp = n
    for p in range(2, int(n**.5)+1):
        if tmp % p == 0:
            cnt = 0
            while tmp % p == 0:
                cnt += 1
                tmp //= p
            retval.append([p, cnt])
    if tmp != 1:
        retval.append([tmp, 1])
    return retval


fact = factorization(n)
m = len(fact)
ans = 0
for i in range(1, 1000):
    for j in range(m):
        if i <= fact[j][1]:
            fact[j][1] -= i
            ans += 1
print(ans)
