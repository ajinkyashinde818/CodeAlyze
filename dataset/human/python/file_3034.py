def prime_factorize(n):
    a = []
    N = n
    cnt = 0
    while n % 2 == 0:
        cnt += 1
        n //= 2
    if cnt > 0:
        a.append(cnt)
    f = 3
    cnt = 0
    while f * f <= N:

        if n % f == 0:
            cnt += 1
            n //= f
        else:
            f += 2
            if cnt > 0:
                a.append(cnt)
            cnt = 0

    if n != 1:
        a.append(1)
    return a

n = int(input())
ans = 0
lis = prime_factorize(n)
#print(lis)

for i in range(len(lis)):
    val = 1
    while val <= lis[i]:
        lis[i] -= val
        val += 1
        ans += 1
print(ans)
